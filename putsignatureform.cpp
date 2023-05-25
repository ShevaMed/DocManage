#include "putsignatureform.h"
#include "ui_putsignatureform.h"
#include "dbmanager.h"
#include "docoperations.h"
#include "messagehandler.h"

#include <QSqlRecord>
#include <QSqlField>

PutSignatureForm::PutSignatureForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PutSignatureForm),
    documentsModel_(DBManager::instance().getDocumentsModel())
{
    ui->setupUi(this);
    this->resize(800, 450);
    this->setFocus();

    ui->documentsTableView->setModel(documentsModel_);
    ui->documentsTableView->setColumnHidden(5, true);
    ui->documentsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QStringList docIds = DBManager::selectDocIdsFromDocUser(DBManager::userId);
    if (docIds.isEmpty()) {
        documentsModel_->setFilter("documents.id = -1");
    } else {
        QString docFilter = QString("documents.id IN (%1)").arg(docIds.join(", "));
        documentsModel_->setFilter(docFilter);
    }
}

PutSignatureForm::~PutSignatureForm()
{
    delete ui;
}

void PutSignatureForm::on_openDocButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    QByteArray content = documentsModel_->record(currDocRow).field("content").value().toByteArray();
    DocOperations::open(this, content);
}


void PutSignatureForm::on_saveCommentButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    int docId = documentsModel_->record(currDocRow).field("id").value().toInt();
    if (DBManager::updateDocUser(docId, DBManager::userId, ui->userNoteTextEdit->toPlainText())) {
        MessageHandler::showSuccessInfo(this, "Коментар збережено!");
    }
}


void PutSignatureForm::on_exitButton_clicked()
{
    this->close();
}


void PutSignatureForm::on_saveAsDocButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    QString docName = documentsModel_->record(currDocRow).field("document_name").value().toString();
    QByteArray content = documentsModel_->record(currDocRow).field("content").value().toByteArray();
    DocOperations::saveAs(this, docName, content);
}


void PutSignatureForm::on_putSignatureButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    QByteArray signature = DBManager::selectSignFromUsers(DBManager::userId);
    if (signature.isEmpty()) {
        MessageHandler::showEmptySignWarning(this);
        return;
    }

    int signWidth = DBManager::selectValueFromSettings("Ширина підпису").toInt();
    int signHeight = DBManager::selectValueFromSettings("Висота підпису").toInt();
    if (signWidth <= 0 || signHeight <= 0) {
        return;
    }

    auto [firstName, lastName] = DBManager::selectFLNameFromUsers(DBManager::userId);
    if (firstName.isEmpty() || lastName.isEmpty()) {
        return;
    }

    QByteArray content = documentsModel_->record(currDocRow).field("content").value().toByteArray();
    if (content.isEmpty()) {
        MessageHandler::showEmptyFileWarning(this);
        return;
    }

    QString textForPutSign = firstName + ' ' + lastName;
    qDebug() << textForPutSign;
    QString docName = documentsModel_->record(currDocRow).field("document_name").value().toString();
    QByteArray signedContent = DocOperations::putSignature(this, docName, content, signature,
                                                           textForPutSign, signWidth, signHeight);
    if (signedContent.isEmpty()) {
        MessageHandler::showInvalidPutSignWarning(this);
        return;
    }

    int docId = documentsModel_->record(currDocRow).field("id").value().toInt();
    if (DBManager::updateDocuments(docId, signedContent) &&
            DBManager::updateDocUser(docId, DBManager::userId, true)) {
        MessageHandler::showSuccessInfo(this, "Документ успішно підписано!");
    }
}


void PutSignatureForm::on_documentsTableView_clicked(const QModelIndex &index)
{
    QString docNote = documentsModel_->record(index.row()).field("note").value().toString();
    ui->noteTextEdit->setPlainText(docNote);

    int docId = documentsModel_->record(index.row()).field("id").value().toInt();
    QString userNote = DBManager::selectUserNoteFromDocUser(docId);
    ui->userNoteTextEdit->setPlainText(userNote);
}

