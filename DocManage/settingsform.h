#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = nullptr);
    ~SettingsForm();

private slots:
    void on_settingsTableView_clicked(const QModelIndex &index);

    void on_saveButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::SettingsForm *ui;
    QSqlRelationalTableModel *settingsModel_;
};

#endif // SETTINGSFORM_H
