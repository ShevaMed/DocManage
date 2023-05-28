#include "messagehandler.h"

#include <QMessageBox>

MessageHandler::MessageHandler()
{

}

void MessageHandler::showDBQueryError(QWidget *parent, QString queryError)
{
    QMessageBox::critical(parent, "Помилка запиту до бази даних",
                              "Не вдалося звернутися до бази даних. "
                              "Перевірте налаштування підключення "
                              "або спробуйте ще раз! " + queryError);
}

void MessageHandler::showOpenFileError(QWidget *parent, QString fileName)
{
    QMessageBox::critical(parent, "Помилка відкриття файлу",
                              "Не вдалося відкрити файл. "
                              "Перевірте, що файл " + fileName +
                              " розташований у папці програми.");
}

void MessageHandler::showOpenDatabaseError(QWidget *parent, QString databaseError)
{
    QMessageBox::critical(parent, "Помилка підключення бази данных",
                              "Не вдалося підключитися до бази даних. "
                              "Перевірте налаштування підключення! " +
                          databaseError);
}

void MessageHandler::showEmptySignWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Помилка скачування підпису",
                              "Не вдалося скачати підпис із бази даних. "
                              "Ви ще не зберігали свій підпис!");
}

void MessageHandler::showEmptyFileWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Файл ще не завантажений",
                              "Не вдалося взяти дані файлу. "
                              "Ви ще не завантажили файл!");
}

void MessageHandler::showEmptyEditWarning(QWidget *parent, QString whomIsEmpty)
{
    QMessageBox::warning(parent, "Некоректні дані", "Ви ввели некоректне поле - " +
                         whomIsEmpty + ". Спробуйте ще раз!");
}

void MessageHandler::showOpenFileWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Помилка відкриття",
                         "Не вдалося відкрити файл. "
                         "Можливо файл неправильно записаний "
                         "або спробуйте ще раз.");
}

void MessageHandler::showInvalidIndexWarning(QWidget *parent, QString whomIsSelected)
{
    QMessageBox::warning(parent, whomIsSelected + " не обрано",
                         "Виберіть " + whomIsSelected + " у таблиці!");
}

void MessageHandler::showSameAccountWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Акаунт вже існує", "Користувач з таким ім'ям "
                                                     "та прізвищем вже існує. "
                                                     "Перевірте коректність даних!");
}

void MessageHandler::showNotExistAccountWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Акаунта не існує", "Користувача з таким ім'ям "
                                                     "та прізвищем не існує. "
                                                     "Перевірте коректність даних!");
}

void MessageHandler::showWrongPasswordWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Неправильний пароль", "Ви ввели неправильний "
                                                        "пароль для цього акаунта. "
                                                        "Спробуйте ще раз!");
}

void MessageHandler::showInvalidPutSignWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Помилка підписання документа",
                         "Не вдалося поставити підпис. "
                         "Спробуйте ще раз!");
}

void MessageHandler::showIsNotNameInDocWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Помилка підписання документа",
                         "Вашого ім'я немає у документі. "
                         "Зверніться до автора документа!");
}

void MessageHandler::showAlreadySignedWarning(QWidget *parent)
{
    QMessageBox::warning(parent, "Помилка підписання документа",
                         "Ви вже підписали цей документ!");
}

void MessageHandler::showSuccessInfo(QWidget *parent, QString message)
{
    QMessageBox::information(parent, "Успіх", message);
}

bool MessageHandler::replyRewriteDocument(QWidget *parent)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "Підтвердити дію",
                                  "Ви вже завантажували файл для цього документа. "
                                  "Ви впевнені, що хочете перезаписати файл?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return false;
    }
    return true;
}

