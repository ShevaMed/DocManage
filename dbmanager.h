#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class DBManager
{
public:
    static DBManager& instance();
    QSqlDatabase& getDatabase();
    QSqlRelationalTableModel* getDocumentsModel();
    QSqlRelationalTableModel* getUsersModel();
    QSqlRelationalTableModel* getDocUserModel();
    QSqlRelationalTableModel* getSettingsModel();

private:
    DBManager();
    ~DBManager();

    DBManager(const DBManager&) = delete;
    void operator=(const DBManager&) = delete;

public:
    static bool execute(QSqlQuery& query);

    static bool insertDocUser(int documentId, int userId);
    static bool insertDocuments(QString documentName, int authorId,
                                QByteArray content, QString documentNote);
    static bool insertUsers(QString firstName, QString lastName, QString userPassword,
                            QString jobTitle, QString userType);

    static bool updateUserSign(int userId, const QByteArray& signature);
    static bool updateDocUser(int documentId, int userId, QString userNote);
    static bool updateDocUser(int documentId, int userId, bool checkSignature);
    static bool updateDocUser(int documentId, bool checkSignature);
    static bool updateSettings(int settingId, QString settingValue);
    static bool updateDocuments(int documentId, QString documentName,
                                QString documentNote, QByteArray content);
    static bool updateDocuments(int documentId, QString documentName,
                                QString documentNote);
    static bool updateDocuments(int documentId, QByteArray content);

    static int selectIdFromUsers(QString firstName, QString lastName);
    static QString selectUserNoteFromDocUser(int documentId, int userId);
    static QVariant selectValueFromSettings(QString nameOfSetting);
    static QStringList selectUserIdsFromDocUser(int documentId);
    static QStringList selectDocIdsFromDocUser(int userId);
    static QStringList selectDocIdsFromDocUser(int userId, bool checkSignature);
    static QPair<QString, QString> selectFLNameFromUsers(int userId);
    static QList<QString> selectFromUsers(QString firstName, QString lastName);
    static QByteArray selectSignFromUsers(int userId);

    static bool deleteDocUser(int documentId, int userId);  

private:
    QSqlDatabase database;
    QSqlRelationalTableModel *documentsModel;
    QSqlRelationalTableModel *usersModel;
    QSqlRelationalTableModel *docUserModel;
    QSqlRelationalTableModel *settingsModel;

public:
    static int userId;
};

#endif // DBMANAGER_H
