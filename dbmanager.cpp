#include "dbmanager.h"

#include <QSettings>

DBManager &DBManager::instance()
{
    static DBManager instance;
    return instance;
}

QSqlDatabase &DBManager::getDatabase()
{
    return database;
}

DBManager::DBManager()
{
    QSettings settings("database.ini", QSettings::IniFormat);

    QString host = settings.value("Database/Host").toString();
    int port = settings.value("Database/Port").toInt();
    QString username = settings.value("Database/Username").toString();
    QString password = settings.value("Database/Password").toString();
    QString databaseName = settings.value("Database/DatabaseName").toString();
    int connectTimeout = settings.value("Database/MYSQL_OPT_CONNECT_TIMEOUT").toInt();

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT=" + QString::number(connectTimeout));
    database.setHostName(host);
    database.setPort(port);
    database.setUserName(username);
    database.setPassword(password);
    database.setDatabaseName(databaseName);

}

DBManager::~DBManager()
{
    if (database.isOpen()) {
        database.close();
    }
}
