#include "loadsenddocform.h"
#include "ui_loadsenddocform.h"
#include "dbmanager.h"
#include "loaddocform.h"
#include "docoperations.h"
#include "messagehandler.h"

#include <QSqlRecord>
#include <QSqlField>

LoadSendDocForm::LoadSendDocForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadSendDocForm),
    documentsModel_(DBManager::instance().getDocumentsModel()),
    usersModel_(DBManager::instance().getUsersModel()),
    docUserModel_(DBManager::instance().getDocUserModel())
{
    ui->setupUi(this);
    this->resize(1024, 576);

    ui->documentsTableView->setModel(documentsModel_);
    ui->documentsTableView->setColumnHidden(5, true);
    ui->documentsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->usersTableView->setModel(usersModel_);
    ui->usersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->usersTableView->setColumnHidden(0, true);
    ui->usersTableView->setColumnHidden(3, true);
    ui->usersTableView->setColumnHidden(6, true);

    ui->docUserTableView->setModel(docUserModel_);
    ui->docUserTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->docUserTableView->setColumnHidden(0, true);

    this->removeTablesSelection();
}

LoadSendDocForm::~LoadSendDocForm()
{
    delete ui;
}

void LoadSendDocForm::removeTablesSelection()
{
    documentsModel_->setFilter("");
    ui->documentsTableView->setCurrentIndex({});
    ui->usersTableView->setCurrentIndex({});
    usersModel_->setFilter("");
    ui->docUserTableView->setCurrentIndex({});
    docUserModel_->setFilter("document_id = 0");
}

void LoadSendDocForm::on_loadDocButton_clicked()
{
    LoadDocForm loadDocForm;
    loadDocForm.setModal(true);
    loadDocForm.exec();
    documentsModel_->select();
}


void LoadSendDocForm::on_editDocButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    int docId = documentsModel_->record(currDocRow).field("id").value().toInt();
    QString docName = documentsModel_->record(currDocRow).field("document_name").value().toString();
    QString docNote = documentsModel_->record(currDocRow).field("note").value().toString();

    LoadDocForm loadDocForm(docId, docName, docNote);
    loadDocForm.setModal(true);
    loadDocForm.exec();
    documentsModel_->select();
}


void LoadSendDocForm::on_exitButton_clicked()
{
    this->close();
}


void LoadSendDocForm::on_openDocButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }
    QByteArray content = documentsModel_->record(currDocRow).field("content").value().toByteArray();
    DocOperations::open(this, content);
}


void LoadSendDocForm::on_saveAsDocButton_clicked()
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


void LoadSendDocForm::on_addUserToolButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    int currUserRow = ui->usersTableView->currentIndex().row();
    if (currUserRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Підписанта");
        return;
    }

    int documentId = documentsModel_->record(currDocRow).field("id").value().toInt();
    int userId = usersModel_->record(currUserRow).field("id").value().toInt();

    if (DBManager::insertDocUser(documentId, userId)) {
        docUserModel_->select();

        QString newFilter = usersModel_->filter();
        if (newFilter.isEmpty()) {
            newFilter = QString("id NOT IN (%1)").arg(userId);
        }
        else {
            newFilter.replace(")", QString(", %1)").arg(userId));
        }
        usersModel_->setFilter(newFilter);
    }
}


void LoadSendDocForm::on_documentsTableView_clicked(const QModelIndex &index)
{
    int documentId = documentsModel_->record(index.row()).field("id").value().toInt();
    docUserModel_->setFilter(QString("document_id = %1").arg(documentId));

    QStringList userIds = DBManager::selectUserIdsFromDocUser(documentId);
    if (userIds.isEmpty()) {
        usersModel_->setFilter("");
    }
    else {
        QString userFilter = QString("id NOT IN (%1)").arg(userIds.join(", "));
        usersModel_->setFilter(userFilter);
    }
}


void LoadSendDocForm::on_removeSelectionButton_clicked()
{
    this->removeTablesSelection();
}


void LoadSendDocForm::on_removeUserToolButton_clicked()
{
    int currDocRow = ui->documentsTableView->currentIndex().row();
    if (currDocRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Документ");
        return;
    }

    int currDocUserRow = ui->docUserTableView->currentIndex().row();
    if (currDocUserRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Підписанта");
        return;
    }

    QString firstName = docUserModel_->record(currDocUserRow).field("first_name").value().toString();
    QString lastName = docUserModel_->record(currDocUserRow).field("last_name").value().toString();
    int userId = DBManager::selectIdFromUsers(firstName, lastName);
    if (userId <= 0) {
        return;
    }

    int documentId = documentsModel_->record(currDocRow).field("id").value().toInt();
    if (DBManager::deleteDocUser(documentId, userId)) {
        docUserModel_->select();

        QString newFilter = usersModel_->filter();
        QString userIdStr = QString::number(userId);
        if (newFilter.contains('(' + userIdStr + ')')) {
            newFilter = "";
        }
        else {
            newFilter = newFilter.remove(userIdStr + ", ");
            newFilter = newFilter.remove(", " + userIdStr);
        }
        usersModel_->setFilter(newFilter);
    }
}

