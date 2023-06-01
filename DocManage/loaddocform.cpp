#include "loaddocform.h"
#include "ui_loaddocform.h"
#include "dbmanager.h"
#include "messagehandler.h"

#include <QFileDialog>

LoadDocForm::LoadDocForm(int documentId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadDocForm),
    documentId_(documentId)
{
    ui->setupUi(this);
    this->resize(450, 400);
    this->setWindowIcon(QIcon(":/icons/icons/loadIcon.png"));
}

LoadDocForm::LoadDocForm(QWidget *parent) :
    LoadDocForm(-1, parent)
{
    this->setWindowTitle("Завантаження документу");
}

LoadDocForm::LoadDocForm(int documentId, QString documentName,
                         QString documentNote, QWidget *parent) :
    LoadDocForm(documentId, parent)
{
    this->setWindowTitle("Редагування документу №" + QString::number(documentId));
    ui->nameEdit->setText(documentName);
    ui->noteTextEdit->setText(documentNote);
}

LoadDocForm::~LoadDocForm()
{
    delete ui;
}

void LoadDocForm::on_exitButton_clicked()
{
    this->close();
}


void LoadDocForm::on_setNameOfPathCheckBox_stateChanged(int arg1)
{
    if (arg1 > 0) {
        if (path_.isEmpty()) {
            MessageHandler::showEmptyFileWarning(this);
            ui->setNameOfPathCheckBox->setChecked(0);
            return;
        }
        QFileInfo fileInfo(path_);
        ui->nameEdit->setText(fileInfo.baseName());
    }
}


void LoadDocForm::on_loadButton_clicked()
{
    if (documentId_ >= 0 && !MessageHandler::replyRewriteDocument(this)) {
        return;
    }
    path_ = QFileDialog::getOpenFileName(this, "Обрати документ",
                                                "C:/Users/Public/Documents/",
                                                "MS Word Document (*.docx *.doc);");
    ui->pathLabel->setText(ui->pathLabel->text() + path_);
}


void LoadDocForm::on_saveButton_clicked()
{
    QString docName = ui->nameEdit->text();
    if (docName.isEmpty()) {
        MessageHandler::showEmptyEditWarning(this, "Назву документа");
        return;
    }

    QString docNote = ui->noteTextEdit->toPlainText();

    if (path_.isEmpty()) {
        if (documentId_ < 0) {
            MessageHandler::showEmptyFileWarning(this);
        }
        else if (DBManager::updateDocuments(documentId_, docName, docNote)) {
            MessageHandler::showSuccessInfo(this, "Документ успішно оновлений у базі даних!");
        }
        return;
    }

    QFile document(path_);
    if (!document.open(QIODevice::ReadOnly)) {
        MessageHandler::showOpenFileWarning(this);
        return;
    }
    QByteArray content = document.readAll();
    document.close();

    if (documentId_ >= 0) {
        if (DBManager::updateDocuments(documentId_, docName, docNote, content) &&
                DBManager::updateDocUser(documentId_, false)) {
            MessageHandler::showSuccessInfo(this, "Документ успішно оновлений у базі даних!");
        }
    }
    else if (DBManager::insertDocuments(docName, DBManager::userId, content, docNote)) {
        MessageHandler::showSuccessInfo(this,"Документ успішно завантажено у базу даних!");
    }
}

