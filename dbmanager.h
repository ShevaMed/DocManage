#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>

class DBManager
{
public:
    static DBManager& instance();

    QSqlDatabase& getDatabase();

private:
    QSqlDatabase database;

    DBManager();
    ~DBManager();

    DBManager(const DBManager&) = delete;
    void operator=(const DBManager&) = delete;
};

#endif // DBMANAGER_H
