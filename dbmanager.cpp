#include "dbmanager.h"
#include "messagehandler.h"

#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

DBManager &DBManager::instance()
{
    static DBManager instance;
    return instance;
}

QSqlDatabase &DBManager::getDatabase()
{
    return database;
}

int DBManager::userId = -1;

QSqlRelationalTableModel *DBManager::getDocumentsModel()
{
    if (!documentsModel) {
        documentsModel = new QSqlRelationalTableModel(nullptr, database);
        documentsModel->setTable("documents");
        documentsModel->setRelation(documentsModel->fieldIndex("author_id"),
                                    QSqlRelation("users", "id", "first_name, last_name"));
        documentsModel->select();
        documentsModel->setHeaderData(0, Qt::Horizontal, "ID документа", Qt::DisplayRole);
        documentsModel->setHeaderData(1, Qt::Horizontal, "Назва документа", Qt::DisplayRole);
        documentsModel->setHeaderData(2, Qt::Horizontal, "Ім'я автора", Qt::DisplayRole);
        documentsModel->setHeaderData(3, Qt::Horizontal, "Прізвище автора", Qt::DisplayRole);
        documentsModel->setHeaderData(4, Qt::Horizontal, "Дата завантаження", Qt::DisplayRole);
        documentsModel->setHeaderData(6, Qt::Horizontal, "Примітка до документа", Qt::DisplayRole);
    }
    return documentsModel;
}

QSqlRelationalTableModel *DBManager::getUsersModel()
{
    if (!usersModel) {
        usersModel = new QSqlRelationalTableModel(nullptr, database);
        usersModel->setTable("users");
        usersModel->select();
        usersModel->setHeaderData(1, Qt::Horizontal, "Ім'я", Qt::DisplayRole);
        usersModel->setHeaderData(2, Qt::Horizontal, "Прізвище", Qt::DisplayRole);
        usersModel->setHeaderData(4, Qt::Horizontal, "Посада", Qt::DisplayRole);
        usersModel->setHeaderData(5, Qt::Horizontal, "Тип акаунта", Qt::DisplayRole);
    }
    return usersModel;
}

QSqlRelationalTableModel *DBManager::getDocUserModel()
{
    if (!docUserModel) {
        docUserModel = new QSqlRelationalTableModel(nullptr, database);
        docUserModel->setTable("document_user");
        docUserModel->setRelation(docUserModel->fieldIndex("user_id"),
                                    QSqlRelation("users", "id", "first_name, last_name"));
        docUserModel->select();
        docUserModel->setHeaderData(1, Qt::Horizontal, "Ім'я", Qt::DisplayRole);
        docUserModel->setHeaderData(2, Qt::Horizontal, "Прізвище ", Qt::DisplayRole);
        docUserModel->setHeaderData(3, Qt::Horizontal, "Підпис", Qt::DisplayRole);
        docUserModel->setHeaderData(4, Qt::Horizontal, "Коментар підписанта", Qt::DisplayRole);
        docUserModel->setFilter("document_id = 0");
    }
    return docUserModel;
}

QSqlRelationalTableModel *DBManager::getSettingsModel()
{
    if (!settingsModel) {
        settingsModel = new QSqlRelationalTableModel(nullptr, database);
        settingsModel->setTable("settings");
        settingsModel->select();
        settingsModel->setHeaderData(0, Qt::Horizontal, "ID Параметра", Qt::DisplayRole);
        settingsModel->setHeaderData(1, Qt::Horizontal, "Назва параметра", Qt::DisplayRole);
        settingsModel->setHeaderData(2, Qt::Horizontal, "Значення параметра", Qt::DisplayRole);
    }
    return settingsModel;
}

DBManager::DBManager() :
    documentsModel(nullptr), usersModel(nullptr),
    docUserModel(nullptr), settingsModel(nullptr)
{
    QSettings settings("database.ini", QSettings::IniFormat);

    QString host = settings.value("Database/Host").toString();
    int port = settings.value("Database/Port").toInt();
    QString username = settings.value("Database/Username").toString();
    QString password = settings.value("Database/Password").toString();
    QString databaseName = settings.value("Database/DatabaseName").toString();
    int connectTimeout = settings.value("Database/MYSQL_OPT_CONNECT_TIMEOUT").toInt();

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(host);
    database.setPort(port);
    database.setUserName(username);
    database.setPassword(password);
    database.setDatabaseName(databaseName);
    database.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT=" + QString::number(connectTimeout));
}

bool DBManager::execute(QSqlQuery& query)
{
    if (!query.exec()) {
        MessageHandler::showDBQueryError(nullptr, query.lastError().text());
        return false;
    }
    return true;
}

bool DBManager::insertDocUser(int documentId, int userId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO document_user (document_id, user_id, check_signature) "
                  "VALUES (:document_id, :user_id, :check_signature)");
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);
    query.bindValue(":check_signature", false);
    return DBManager::execute(query);
}

QStringList DBManager::selectUserIdsFromDocUser(int documentId)
{
    QSqlQuery query;
    query.prepare("SELECT user_id FROM document_user WHERE document_id = :document_id");
    query.bindValue(":document_id", documentId);

    QStringList userIds;
    if (DBManager::execute(query)) {
        while (query.next()) {
            userIds.append(query.value("user_id").toString());
        }
    }
    return userIds;
}

QStringList DBManager::selectDocIdsFromDocUser(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT document_id FROM document_user WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);

    QStringList documentIds;
    if (DBManager::execute(query)) {
        while (query.next()) {
            documentIds.append(query.value("document_id").toString());
        }
    }
    return documentIds;
}

QStringList DBManager::selectDocIdsFromDocUser(int userId, bool checkSignature)
{
    QSqlQuery query;
    query.prepare("SELECT document_id FROM document_user "
                  "WHERE user_id = :user_id AND check_signature = :check_signature");
    query.bindValue(":user_id", userId);
    query.bindValue(":check_signature", checkSignature);

    QStringList documentIds;
    if (DBManager::execute(query)) {
        while (query.next()) {
            documentIds.append(query.value("document_id").toString());
        }
    }
    return documentIds;
}

QString DBManager::selectUserNoteFromDocUser(int documentId, int userId)
{
    QSqlQuery query;
    query.prepare("SELECT user_note FROM document_user "
                  "WHERE document_id = :document_id and user_id = :user_id");
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);

    if (DBManager::execute(query) && query.next()) {
        return query.value("user_note").toString();
    }
    return {};
}

int DBManager::selectIdFromUsers(QString firstName, QString lastName)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM users "
                  "WHERE first_name = :first_name AND last_name = :last_name");
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);

    if (DBManager::execute(query) && query.next()) {
        return query.value("id").toInt();
    }
    return -1;
}

QList<QString> DBManager::selectFromUsers(QString firstName, QString lastName)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users "
                  "WHERE first_name = :first_name AND last_name = :last_name");
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);

    QList<QString> result;
    if (DBManager::execute(query) && query.next()) {
        result.push_back(query.value("id").toString());
        result.push_back(query.value("user_password").toString());
        result.push_back(query.value("job_title").toString());
        result.push_back(query.value("user_type").toString());
    }
    return result;
}

QPair<QString, QString> DBManager::selectFLNameFromUsers(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT first_name, last_name FROM users WHERE id = :id");
    query.bindValue(":id", userId);

    if (DBManager::execute(query) && query.next()) {
        QString first_name = query.value("first_name").toString();
        QString last_name = query.value("last_name").toString();

        return QPair<QString, QString>(first_name, last_name);
    }
    return {};
}

QVariant DBManager::selectValueFromSettings(QString nameOfSetting)
{
    QSqlQuery query;
    query.prepare("SELECT value_ FROM settings WHERE name_ = :name_");
    query.bindValue(":name_", nameOfSetting);

    if (DBManager::execute(query) && query.next()) {
        return query.value("value_");
    }
    return {};
}

bool DBManager::deleteDocUser(int documentId, int userId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM document_user "
                  "WHERE document_id = :document_id AND user_id = :user_id");
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);
    return DBManager::execute(query);
}

bool DBManager::updateUserSign(int userId, const QByteArray &signature)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET signature = :sign WHERE id = :id");
    query.bindValue(":sign", signature);
    query.bindValue(":id", userId);
    return DBManager::execute(query);
}

bool DBManager::updateDocUser(int documentId, int userId, QString userNote)
{
    QSqlQuery query;
    query.prepare("UPDATE document_user SET user_note = :user_note "
                  "WHERE document_id = :document_id AND user_id = :user_id");
    query.bindValue(":user_note", userNote);
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);
    return DBManager::execute(query);
}

bool DBManager::updateDocUser(int documentId, int userId, bool checkSignature)
{
    QSqlQuery query;
    query.prepare("UPDATE document_user SET check_signature = :check_signature "
                  "WHERE document_id = :document_id AND user_id = :user_id");
    query.bindValue(":check_signature", checkSignature);
    query.bindValue(":document_id", documentId);
    query.bindValue(":user_id", userId);
    return DBManager::execute(query);
}

bool DBManager::updateDocUser(int documentId, bool checkSignature)
{
    QSqlQuery query;
    query.prepare("UPDATE document_user SET check_signature = :check_signature "
                  "WHERE document_id = :document_id");
    query.bindValue(":check_signature", checkSignature);
    query.bindValue(":document_id", documentId);
    return DBManager::execute(query);
}

bool DBManager::updateSettings(int settingId, QString settingValue)
{
    QSqlQuery query;
    query.prepare("UPDATE settings SET value_ = :value_ WHERE id = :id");
    query.bindValue(":value_", settingValue);
    query.bindValue(":id", settingId);
    return DBManager::execute(query);
}

QByteArray DBManager::selectSignFromUsers(int userId)
{
    QSqlQuery query;
    query.prepare("SELECT signature FROM users WHERE id = :id");
    query.bindValue(":id", userId);

    if (DBManager::execute(query) && query.next()) {
        return query.value("signature").toByteArray();
    }
    return {};
}

bool DBManager::updateDocuments(int documentId, QString documentName, QString documentNote,
                                QByteArray content)
{
    QSqlQuery query;
    query.prepare("UPDATE documents SET document_name = :document_name, note = :note, "
                  "download_date = :download_date, content = :content WHERE id = :id");
    query.bindValue(":document_name", documentName);
    query.bindValue(":note", documentNote);
    query.bindValue(":download_date", QDate::currentDate());
    query.bindValue(":content", content);
    query.bindValue(":id", documentId);
    return DBManager::execute(query);
}

bool DBManager::updateDocuments(int documentId, QString documentName, QString documentNote)
{
    QSqlQuery query;
    query.prepare("UPDATE documents SET document_name = :document_name, note = :note "
                  "WHERE id = :id");
    query.bindValue(":document_name", documentName);
    query.bindValue(":note", documentNote);
    query.bindValue(":id", documentId);
    return DBManager::execute(query);
}

bool DBManager::updateDocuments(int documentId, QByteArray content)
{
    QSqlQuery query;
    query.prepare("UPDATE documents SET content = :content WHERE id = :id");
    query.bindValue(":content", content);
    query.bindValue(":id", documentId);
    return DBManager::execute(query);
}

bool DBManager::insertDocuments(QString documentName, int authorId, QByteArray content,
                                QString documentNote)
{
    QSqlQuery query;
    query.prepare("INSERT INTO documents (document_name, author_id, "
                  "download_date, content, note) "
                  "VALUES (:document_name, :author_id, :download_date, :content, :note)");
    query.bindValue(":document_name", documentName);
    query.bindValue(":author_id", authorId);
    query.bindValue(":download_date", QDate::currentDate());
    query.bindValue(":content", content);
    query.bindValue(":note", documentNote);
    return DBManager::execute(query);
}

bool DBManager::insertUsers(QString firstName, QString lastName, QString userPassword,
                            QString jobTitle, QString userType)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (first_name, last_name, user_password, job_title, user_type) "
                  "VALUES (:first_name, :last_name, :user_password, :job_title, :user_type)");
    query.bindValue(":first_name", firstName);
    query.bindValue(":last_name", lastName);
    query.bindValue(":user_password", userPassword);
    query.bindValue(":job_title", jobTitle);
    query.bindValue(":user_type", userType);
    return DBManager::execute(query);
}

DBManager::~DBManager()
{
    if (documentsModel) {
        delete documentsModel;
    }
    if (usersModel) {
        delete usersModel;
    }
    if (docUserModel) {
        delete docUserModel;
    }
    if (settingsModel) {
        delete settingsModel;
    }
    if (database.isOpen()) {
        database.close();
    }
}
