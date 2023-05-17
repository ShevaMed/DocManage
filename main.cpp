#include "mainwindow.h"
#include "dbmanager.h"

#include <QApplication>
#include <QMessageBox>
#include <Windows.h>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbConfigFileName = "database.ini";
    QFile dbConfigFile(dbConfigFileName);
    if (!dbConfigFile.open(QFile::ReadOnly)) {
        QMessageBox::critical(nullptr, "Помилка відкриття файлу",
                                  "Не вдалося відкрити файл конфігурації бази "
                                  "даних. Перевірте, що файл " + dbConfigFileName +
                                  " розташований у папці програми.");
        return 1;
    }
    dbConfigFile.close();

    QSqlDatabase& db = DBManager::instance().getDatabase();
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Помилка підключення бази данных",
                                  "Не вдалося підключитися до бази даних. "
                                  "Перевірте налаштування підключення! " +
                                  db.lastError().text());
        return 1;
    }

    QString styleSheetFileName = "SyNet.qss";
    QFile styleSheetFile(styleSheetFileName);
    if (styleSheetFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
    } else {
        QMessageBox::warning(nullptr, "Помилка відкриття файлу",
                                  "Не вдалося відкрити файл стилю. "
                                  "Перевірте, що файл " + styleSheetFileName +
                                  " розташований у папці програми.");
    }

    // Initialize the COM library
    CoInitialize(NULL);

    MainWindow w;
    w.show();
    return a.exec();
}
