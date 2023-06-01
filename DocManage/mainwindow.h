#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void resetLoginSignupTab();

private slots:
    void on_signupButton_clicked();

    void on_loginButton_clicked();

    void on_loadSignatureButton_clicked();

    void on_loadSendDocButton_clicked();

    void on_putSignatureButton_clicked();

    void on_settingsButton_clicked();

    void on_logoutButton_clicked();

    void on_signupTypeAccComboBox_currentTextChanged(const QString &arg1);

    void on_loginExitButton_clicked();

    void on_menuExitButton_clicked();

    void on_loginFnameEdit_cursorPositionChanged(int arg1, int arg2);

    void on_loginLnameEdit_cursorPositionChanged(int arg1, int arg2);

    void on_signupFnameEdit_cursorPositionChanged(int arg1, int arg2);

    void on_signupLnameEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
