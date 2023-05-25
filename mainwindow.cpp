#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include "messagehandler.h"
#include "loadsignatureform.h"
#include "loadsenddocform.h"
#include "putsignatureform.h"
#include "settingsform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(700, 500);

    //ui->stackedWidget->setCurrentWidget(ui->loginPage);
    //ui->tabWidget->setCurrentWidget(ui->loginTab);
    ui->signupTypeAccComboBox->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signupButton_clicked()
{
    if (ui->signupFnameEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Ім'я");
        return;
    }

    if (ui->signupLnameEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Прізвище");
        return;
    }

    int checkID = DBManager::selectIdFromUsers(ui->signupFnameEdit->text(),
                                               ui->signupLnameEdit->text());
    if (checkID >= 0) {
        MessageHandler::showSameAccountWarning(this);
        return;
    }

    if (ui->signupPasswordEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Пароль");
        return;
    }

    if (ui->signupRepPasswordEdit->text() != ui->signupPasswordEdit->text()) {
        MessageHandler::showEmptyEditWarning(this, "Повторити пароль");
        return;
    }

    if (ui->signupJobTitleEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Посада");
        return;
    }

    if (ui->signupTypeAccComboBox->currentText() == "Менеджер") {     
        int regCode = DBManager::selectValueFromSettings("Код для реєстрації менеджера").toInt();
        if (regCode != ui->signupManageCodeEdit->text().toInt()) {
            MessageHandler::showEmptyEditWarning(this, "Код для реєстрації менеджера");
            return;
        }
    }

    if (DBManager::insertUsers(ui->signupFnameEdit->text(), ui->signupLnameEdit->text(),
                           ui->signupPasswordEdit->text(), ui->signupJobTitleEdit->text(),
                           ui->signupTypeAccComboBox->currentText())) {
        MessageHandler::showSuccessInfo(this, "Акаунт успішно зареєстрований!");
    }
}


void MainWindow::on_loginButton_clicked()
{
    if (ui->loginFnameEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Ім'я");
        return;
    }

    if (ui->loginLnameEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Прізвище");
        return;
    }

    if (ui->loginPasswordEdit->text().length() < 3) {
        MessageHandler::showEmptyEditWarning(this, "Пароль");
        return;
    }

    QList<QString> userInfo = DBManager::selectFromUsers(ui->loginFnameEdit->text(),
                                                         ui->loginLnameEdit->text());
    if (userInfo.isEmpty()) {
        MessageHandler::showNotExistAccountWarning(this);
        return;
    }

    if (ui->loginPasswordEdit->text() != userInfo.at(1)) {
        MessageHandler::showWrongPasswordWarning(this);
        return;
    }

    ui->stackedWidget->setCurrentWidget(ui->menuPage);
    ui->menuUserNameLabel->setText("Вітаємо, " + ui->loginFnameEdit->text() + ' ' +
                                   ui->loginLnameEdit->text() + '!');
    ui->menuJobTitleLabel->setText("Посада: " + userInfo.at(2));
    ui->menuTypeAccLabel->setText("Тип акаунта: " + userInfo.at(3));

    DBManager::userId = userInfo.at(0).toInt();
}


void MainWindow::on_loadSignatureButton_clicked()
{
    int signWidth = DBManager::selectValueFromSettings("Ширина підпису").toInt();
    int signHeight = DBManager::selectValueFromSettings("Висота підпису").toInt();
    if (signWidth > 0 && signHeight > 0) {
        LoadSignatureForm loadSignatureForm(signWidth, signHeight);
        loadSignatureForm.setModal(true);
        this->hide();
        loadSignatureForm.exec();
        this->show();
    }
}


void MainWindow::on_loadSendDocButton_clicked()
{
    LoadSendDocForm loadSendDocForm;
    loadSendDocForm.setModal(true);
    this->hide();
    loadSendDocForm.exec();
    this->show();
}


void MainWindow::on_putSignatureButton_clicked()
{
    PutSignatureForm putSignatureForm;
    putSignatureForm.setModal(true);
    this->hide();
    putSignatureForm.exec();
    this->show();
}


void MainWindow::on_settingsButton_clicked()
{
    SettingsForm settingsForm;
    settingsForm.setModal(true);
    this->hide();
    settingsForm.exec();
    this->show();
}


void MainWindow::on_logoutButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    DBManager::userId = -1;
}


void MainWindow::on_signupTypeAccComboBox_currentTextChanged(const QString &arg1)
{
    if ("Підписант" == arg1) {
        ui->signupCodeHorizontalSpacer->changeSize(0, 20);
        ui->signupManageCodeEdit->hide();
        ui->signupManageCodeLabel->hide();
    }
    else if ("Менеджер" == arg1) {
        ui->signupCodeHorizontalSpacer->changeSize(20, 20);
        ui->signupManageCodeEdit->show();
        ui->signupManageCodeLabel->show();
    }
}


void MainWindow::on_loginExitButton_clicked()
{
    this->close();
}


void MainWindow::on_menuExitButton_clicked()
{
    this->close();
}

