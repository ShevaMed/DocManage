#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_signupButton_clicked();

    void on_loginButton_clicked();

    void on_loadSignatureButton_clicked();

    void on_loadSendDocButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    int userId_;
    int signWidth_, signHeight_;
};
#endif // MAINWINDOW_H
