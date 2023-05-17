#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include "loadsignatureform.h"
#include "loadsenddocform.h"

#include <QSpacerItem>
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      db(DBManager::instance().getDatabase()),
      userId_(0), signWidth_(77), signHeight_(23)
{
    ui->setupUi(this);

    auto& lineEditRef = ui->signupManageCodeEdit;
    auto& labelRef = ui->signupManageCodeLabel;
    auto& spacerRef = ui->signupCodeHorizontalSpacer;

    connect(ui->signupTypeAccComboBox, &QComboBox::currentTextChanged, this,
            [lineEditRef, labelRef, spacerRef](const QString& text)
    {
        if (text == "Підписант") {
            spacerRef->changeSize(0, 20);
            lineEditRef->hide();
            labelRef->hide();
        }
        else if (text == "Менеджер") {
            spacerRef->changeSize(20, 20);
            lineEditRef->show();
            labelRef->show();
        }
    });

    ui->signupTypeAccComboBox->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_signupButton_clicked()
{
    if (ui->signupFnameEdit->text().length() < 3) {
        QMessageBox::warning(this, "Некоректне ім'я", "Ви ввели некоректне ім'я. "
                                                      "Спробуйте ще раз!");
        return;
    }

    if (ui->signupLnameEdit->text().length() < 3) {
        QMessageBox::warning(this, "Некоректне прізвище", "Ви ввели некоректне прізвище. "
                                                          "Спробуйте ще раз!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE first_name = :first_name AND last_name = :last_name");
    query.bindValue(":first_name", ui->signupFnameEdit->text());
    query.bindValue(":last_name", ui->signupLnameEdit->text());

    if (query.exec() && query.next()) {
        QMessageBox::warning(this, "Акаунт вже існує", "Користувач з таким ім'ям та прізвищем вже "
                                                       "існує. Перевірте коректність даних!");
        return;
    }

    if (ui->signupPasswordEdit->text().length() < 3) {
        QMessageBox::warning(this, "Некоректний пароль", "Ви ввели некоректний пароль. "
                                                         "Спробуйте ще раз!");
        return;
    }

    if (ui->signupRepPasswordEdit->text() != ui->signupPasswordEdit->text()) {
        QMessageBox::warning(this, "Паролі не свівпадають", "Ви ввели паролі, які не свівпадають. "
                                                            "Спробуйте ще раз!");
        return;
    }

    if (ui->signupJobTitleEdit->text().length() < 3) {
        QMessageBox::warning(this, "Некоректна посада", "Ви ввели некоректну посаду. "
                                                         "Спробуйте ще раз!");
        return;
    }

    if (ui->signupTypeAccComboBox->currentText() == "Менеджер") {
        query.clear();
        if (query.exec("SELECT value_ FROM settings WHERE name_ = 'Код для реєстрації менеджера'")
                && query.next()
                && ui->signupManageCodeEdit->text() != query.value("value_").toString()) {
            QMessageBox::warning(this, "Некоректний код", "Ви ввели некоректний код для реєстрації"
                                                          " менеджера. Спробуйте ще раз!");
            return;
        }
    }

    query.clear();
    query.prepare("INSERT INTO users (first_name, last_name, user_password, job_title, user_type) "
                  "VALUES (:first_name, :last_name, :user_password, :job_title, :user_type)");
    query.bindValue(":first_name", ui->signupFnameEdit->text());
    query.bindValue(":last_name", ui->signupLnameEdit->text());
    query.bindValue(":user_password", ui->signupPasswordEdit->text());
    query.bindValue(":job_title", ui->signupJobTitleEdit->text());
    query.bindValue(":user_type", ui->signupTypeAccComboBox->currentText());

    if (!query.exec()) {
        qDebug() << query.lastError().text();
    }
    else {
        QMessageBox::information(this, "Успіх", "Акаунт успішно зареєстрований!");
    }
}


void MainWindow::on_loginButton_clicked()
{
    if (ui->loginFnameEdit->text().length() < 3) {
        QMessageBox::warning(this, "Некоректне ім'я", "Ви ввели некоректне ім'я. "
                                                      "Спробуйте ще раз!");
        return;
    }

    if (ui->loginLnameEdit->text().length() < 3) {
        QMessageBox::warning(this, "Некоректне прізвище", "Ви ввели некоректне прізвище. "
                                                          "Спробуйте ще раз!");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users "
                  "WHERE first_name = :first_name AND last_name = :last_name");
    query.bindValue(":first_name", ui->loginFnameEdit->text());
    query.bindValue(":last_name", ui->loginLnameEdit->text());

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка підключення бази данных",
                                  "Не вдалося підключитися до бази даних. "
                                  "Перевірте налаштування підключення.");
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Акаунта не існує", "Користувача з таким ім'ям"
                                                       " та прізвищем не існує. "
                                                       "Перевірте коректність даних!");
        return;
    }

    if (ui->loginPasswordEdit->text() != query.value("user_password").toString()) {
        QMessageBox::warning(this, "Некоректний пароль", "Ви ввели некоректний пароль. "
                                                         "Спробуйте ще раз!");
        return;
    }

    ui->stackedWidget->setCurrentIndex(1);

    ui->menuUserNameLabel->setText(ui->menuUserNameLabel->text() +
                                   query.value("last_name").toString() + ' ' +
                                   query.value("first_name").toString() + '!');
    ui->menuTypeAccLabel->setText(ui->menuTypeAccLabel->text() +
                                  query.value("user_type").toString());
    userId_ = query.value("id").toInt();

    query.clear();
    query.prepare("SELECT value_ FROM settings "
                  "WHERE name_ = 'Ширина підпису' OR name_ = 'Висота підпису'");

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка підключення бази данных",
                                  "Не вдалося підключитися до бази даних. "
                                  "Перевірте налаштування підключення.");
        return;
    }

    if (query.next()) {
        signHeight_ = query.value("value_").toInt();
        if (query.next()) {
            signWidth_ = query.value("value_").toInt();
        }
    }
}


void MainWindow::on_loadSignatureButton_clicked()
{
    LoadSignatureForm loadSignatureForm(userId_, signWidth_, signHeight_);
    loadSignatureForm.setModal(true);
    hide();
    loadSignatureForm.exec();
    show();
}


void MainWindow::on_loadSendDocButton_clicked()
{
    LoadSendDocForm loadSendDocForm(userId_);
    loadSendDocForm.setModal(true);
    hide();
    loadSendDocForm.exec();
    show();
}

