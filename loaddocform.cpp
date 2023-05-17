#include "loaddocform.h"
#include "ui_loaddocform.h"

#include <QFileDialog>
#include <QSqlQuery>
#include <QMessageBox>

LoadDocForm::LoadDocForm(int userId, int documentId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadDocForm),
    userId_(userId),
    documentId_(documentId)
{
    ui->setupUi(this);
}

LoadDocForm::LoadDocForm(int userId, QWidget *parent) :
    LoadDocForm(userId, 0, parent)
{
    this->setWindowTitle("Завантаження документу");
}

LoadDocForm::LoadDocForm(int userId, int documentId, QString documentName,
                         QString documentNote, QWidget *parent) :
    LoadDocForm(userId, documentId, parent)
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
    close();
}


void LoadDocForm::on_setNameOfPathCheckBox_stateChanged(int arg1)
{
    if (arg1 > 0) {
        if (path_.isEmpty()) {
            QMessageBox::warning(this, "Файл ще не завантажений",
                                      "Не вдалося застосувати назву файлу. "
                                      "Ви ще не завантажили файл!");
            ui->setNameOfPathCheckBox->setChecked(0);
            return;
        }
        QFileInfo fileInfo(path_);
        ui->nameEdit->setText(fileInfo.baseName());
    }
}


void LoadDocForm::on_loadButton_clicked()
{
    if (documentId_ > 0) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Підтвердити дію",
                                      "Ви вже завантажували файл для цього документа. "
                                      "Ви впевнені, що хочете перезаписати файл?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
    }
    path_ = QFileDialog::getOpenFileName(this, "Обрати документ",
                                                "C:/Users/Public/Documents/",
                                                "MS Word Document (*.docx *.doc);");
    ui->pathLabel->setText(ui->pathLabel->text() + path_);
}


void LoadDocForm::on_saveButton_clicked()
{
    if (ui->nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Не вказана назва документу",
                                  "Не вдалося зберегти дані у базу даних. "
                                  "Ви ще не вказали назву документу!");
        return;
    }

    if (path_.isNull() && documentId_ <= 0) {
        QMessageBox::warning(this, "Файл ще не завантажений",
                                          "Не вдалося зберегти дані у базу даних. "
                                          "Ви ще не завантажили файл!");
        return;
    }

    QSqlQuery query;

    if (path_.isEmpty()) {
        query.prepare("UPDATE documents SET document_name = :document_name, note = :note "
                      "WHERE id = :id");
        query.bindValue(":document_name", ui->nameEdit->text());
        query.bindValue(":note", ui->noteTextEdit->toPlainText());
        query.bindValue(":id", documentId_);
    }
    else {
        QFile document(path_);
        if (!document.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Помилка відкриття", "Не вдалося відкрити файл.");
            return;
        }
        QByteArray content = document.readAll();
        document.close();

        if (documentId_ > 0) {
            query.prepare("UPDATE documents SET document_name = :document_name, "
                          "note = :note, content = :content "
                          "WHERE id = :id");
            query.bindValue(":document_name", ui->nameEdit->text());
            query.bindValue(":note", ui->noteTextEdit->toPlainText());
            query.bindValue(":content", content);
            query.bindValue(":id", documentId_);
        }
        else {
            query.prepare("INSERT INTO documents (document_name, author_id, "
                          "download_date, content, note) "
                          "VALUES (:document_name, :author_id, :download_date, :content, :note)");
            query.bindValue(":document_name", ui->nameEdit->text());
            query.bindValue(":author_id", userId_);
            query.bindValue(":download_date", QDate::currentDate());
            query.bindValue(":content", content);
            query.bindValue(":note", ui->noteTextEdit->toPlainText());
        }
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка збереження документу",
                                  "Не вдалося зберегти документ у базу даних. "
                                  "Перевірте налаштування підключення!");
        return;
    }

    QString successMessage;

    if (documentId_ > 0) {
        successMessage = "Документ успішно оновлений у базі даних!";
    }
    else {
        successMessage = "Документ успішно завантажено у базу даних!";
    }
    QMessageBox::information(this, "Успіх", successMessage);
}

