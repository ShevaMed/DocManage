#include "loadsenddocform.h"
#include "ui_loadsenddocform.h"
#include "dbmanager.h"
#include "loaddocform.h"
#include "docoperations.h"

#include <QSqlRecord>
#include <QSqlField>
#include <QMessageBox>
#include <QSqlQuery>

LoadSendDocForm::LoadSendDocForm(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadSendDocForm),
    userId_(userId),
    db(DBManager::instance().getDatabase())
{
    ui->setupUi(this);
    this->resize(1024, 576);
    this->setFocus();
    documentsModel = new QSqlRelationalTableModel(this, db);
    documentsModel->setTable("documents");
    documentsModel->setRelation(documentsModel->fieldIndex("author_id"),
                                QSqlRelation("users", "id", "first_name, last_name"));
    documentsModel->select();
    documentsModel->setHeaderData(0, Qt::Horizontal, "ID", Qt::DisplayRole);
    documentsModel->setHeaderData(1, Qt::Horizontal, "Назва", Qt::DisplayRole);
    documentsModel->setHeaderData(2, Qt::Horizontal, "Ім'я автора", Qt::DisplayRole);
    documentsModel->setHeaderData(3, Qt::Horizontal, "Прізвище автора", Qt::DisplayRole);
    documentsModel->setHeaderData(4, Qt::Horizontal, "Дата завантаження", Qt::DisplayRole);
    documentsModel->setHeaderData(6, Qt::Horizontal, "Примітка до документа", Qt::DisplayRole);

    ui->documentsTableView->setModel(documentsModel);
    ui->documentsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->documentsTableView->setColumnHidden(5, true);

    usersModel = new QSqlRelationalTableModel(this, db);
    usersModel->setTable("users");
    usersModel->select();
    usersModel->setHeaderData(1, Qt::Horizontal, "Ім'я", Qt::DisplayRole);
    usersModel->setHeaderData(2, Qt::Horizontal, "Прізвище", Qt::DisplayRole);
    usersModel->setHeaderData(4, Qt::Horizontal, "Посада", Qt::DisplayRole);
    usersModel->setHeaderData(5, Qt::Horizontal, "Тип акаунта", Qt::DisplayRole);

    ui->usersTableView->setModel(usersModel);
    ui->usersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->usersTableView->setColumnHidden(0, true);
    ui->usersTableView->setColumnHidden(3, true);
    ui->usersTableView->setColumnHidden(6, true);

    docUserModel = new QSqlRelationalTableModel(this, db);
    docUserModel->setTable("document_user");
    docUserModel->setRelation(docUserModel->fieldIndex("user_id"),
                                QSqlRelation("users", "id", "first_name, last_name"));
    docUserModel->select();
    docUserModel->setHeaderData(1, Qt::Horizontal, "Ім'я", Qt::DisplayRole);
    docUserModel->setHeaderData(2, Qt::Horizontal, "Прізвище ", Qt::DisplayRole);
    docUserModel->setHeaderData(3, Qt::Horizontal, "Підпис", Qt::DisplayRole);
    docUserModel->setHeaderData(4, Qt::Horizontal, "Коментар підписанта", Qt::DisplayRole);
    docUserModel->setFilter("document_id = 0");

    ui->docUserTableView->setModel(docUserModel);
    ui->docUserTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->docUserTableView->setColumnHidden(0, true);

}

LoadSendDocForm::~LoadSendDocForm()
{
    delete ui;
}

void LoadSendDocForm::on_loadDocButton_clicked()
{
    LoadDocForm loadDocForm(userId_);
    loadDocForm.setModal(true);
    loadDocForm.exec();
    documentsModel->select();
}


void LoadSendDocForm::on_editDocButton_clicked()
{
    int currRow = DocOperations::getRowIndex(this, ui->documentsTableView, "Документ");
    if (currRow < 0) {
        return;
    }

    int docId = documentsModel->record(currRow).field("id").value().toInt();
    QString docName = documentsModel->record(currRow).field("document_name").value().toString();
    QString docNote = documentsModel->record(currRow).field("note").value().toString();

    LoadDocForm loadDocForm(userId_, docId, docName, docNote);
    loadDocForm.setModal(true);
    loadDocForm.exec();
    documentsModel->select();
}


void LoadSendDocForm::on_exitButton_clicked()
{
    close();
}


void LoadSendDocForm::on_openDocButton_clicked()
{
    int currRow = DocOperations::getRowIndex(this, ui->documentsTableView, "Документ");
    if (currRow < 0) {
        return;
    }
    DocOperations::open(this, documentsModel, currRow);
}


void LoadSendDocForm::on_saveAsDocButton_clicked()
{
    int currRow = DocOperations::getRowIndex(this, ui->documentsTableView, "Документ");
    if (currRow < 0) {
        return;
    }
    DocOperations::saveAs(this, documentsModel, currRow);
}


void LoadSendDocForm::on_addUserToolButton_clicked()
{
    int currDocRow = DocOperations::getRowIndex(this, ui->documentsTableView, "Документ");
    int currUserRow = DocOperations::getRowIndex(this, ui->usersTableView, "Підписанта");
    if (currDocRow < 0 || currUserRow < 0) {
        return;
    }

    int documentId = documentsModel->record(currDocRow).field("id").value().toInt();
    int userId = usersModel->record(currUserRow).field("id").value().toInt();

    QSqlQuery query;
    query.prepare("INSERT INTO document_user (document_id, user_id, check_signature) "
                  "VALUES (:document_id, :user_id, :check_signature)");
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);
    query.bindValue(":check_signature", false);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка додавання підписанта",
                                  "Не вдалося додати підписанта у базу даних. "
                                  "Перевірте налаштування підключення або спробуйте ще раз!");
        return;
    }
    docUserModel->select();

    QString newFilter = usersModel->filter();
    if (newFilter.isEmpty()) {
        newFilter = QString("id NOT IN (%1)").arg(userId);
    }
    else {
        newFilter.replace(")", QString(", %1)").arg(userId));
    }
    usersModel->setFilter(newFilter);
}


void LoadSendDocForm::on_documentsTableView_clicked(const QModelIndex &index)
{
    int idToShow = documentsModel->record(index.row()).field("id").value().toInt();
    QString docUserFilter = QString("document_id = %1").arg(idToShow);
    docUserModel->setFilter(docUserFilter);

    QSqlQuery query;
    query.prepare("SELECT user_id FROM document_user WHERE document_id = :document_id");
    query.bindValue(":document_id", idToShow);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка запиту до бази даних",
                                  "Не вдалося звернутися до бази даних. "
                                  "Перевірте налаштування підключення або спробуйте ще раз!");
        return;
    }

    QStringList userIds;

    while (query.next()) {
        userIds.append(query.value("user_id").toString());
    }

    if (userIds.isEmpty()) {
        usersModel->setFilter("");
    }
    else {
        QString usersFilter = QString("id NOT IN (%1)").arg(userIds.join(", "));
        usersModel->setFilter(usersFilter);
    }
}


void LoadSendDocForm::on_removeSelectionButton_clicked()
{
    ui->documentsTableView->setCurrentIndex({});
    ui->usersTableView->setCurrentIndex({});
    usersModel->setFilter("");
    ui->docUserTableView->setCurrentIndex({});
    docUserModel->setFilter("document_id = 0");
}


void LoadSendDocForm::on_removeUserToolButton_clicked()
{
    int currDocRow = DocOperations::getRowIndex(this, ui->documentsTableView, "Документ");
    int currUserRow = DocOperations::getRowIndex(this, ui->docUserTableView, "Підписанта");
    if (currDocRow < 0 || currUserRow < 0) {
        return;
    }

    int documentId = documentsModel->record(currDocRow).field("id").value().toInt();
    QString userFName = docUserModel->record(currUserRow).field("first_name").value().toString();
    QString userLName = docUserModel->record(currUserRow).field("last_name").value().toString();

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE first_name = :first_name AND last_name = :last_name");
    query.bindValue(":first_name", userFName);
    query.bindValue(":last_name", userLName);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка запиту до бази даних",
                                  "Не вдалося звернутися до бази даних. "
                                  "Перевірте налаштування підключення або спробуйте ще раз!");
        return;
    }

    query.next();
    int userId = query.value("id").toInt();

    query.clear();
    query.prepare("DELETE FROM document_user WHERE document_id = :document_id AND user_id = :user_id");
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка запиту до бази даних",
                                  "Не вдалося звернутися до бази даних. "
                                  "Перевірте налаштування підключення або спробуйте ще раз!");
        return;
    }

    docUserModel->select();

    QString newFilter = usersModel->filter();
    QString userIdStr = QString::number(userId);
    if (newFilter.contains("(" + userIdStr + ")")) {
        newFilter = "";
    }
    else {
        newFilter = newFilter.remove(userIdStr + ", ");
        newFilter = newFilter.remove(", " + userIdStr);
    }
    usersModel->setFilter(newFilter);

}

