#include "mainwindow.h"
#include "dbmanager.h"
#include "messagehandler.h"

#include <QApplication>
#include <Windows.h>
#include <QFile>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbConfigFileName = "database.ini";
    QFile dbConfigFile(dbConfigFileName);
    if (!dbConfigFile.open(QFile::ReadOnly)) {
        MessageHandler::showOpenFileError(nullptr, dbConfigFileName);
        return 1;
    }
    dbConfigFile.close();

    QSqlDatabase& db = DBManager::instance().getDatabase();
    if (!db.open()) {
        MessageHandler::showOpenDatabaseError(nullptr, db.lastError().text());
        return 1;
    }

    QString styleSheetFileName = "stylesheet.qss";
    QFile styleSheetFile(styleSheetFileName);
    if (!styleSheetFile.open(QFile::ReadOnly)) {
        MessageHandler::showOpenFileError(nullptr, styleSheetFileName);
    } else {
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
    }

    // Initialize the COM library
    CoInitialize(NULL);

    MainWindow w;
    w.show();
    return a.exec();
}
