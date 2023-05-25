#ifndef LOADSENDDOCFORM_H
#define LOADSENDDOCFORM_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class LoadSendDocForm;
}

class LoadSendDocForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoadSendDocForm(QWidget *parent = nullptr);
    ~LoadSendDocForm();

private:
    void removeTablesSelection();

private slots:
    void on_loadDocButton_clicked();

    void on_editDocButton_clicked();

    void on_exitButton_clicked();

    void on_openDocButton_clicked();

    void on_saveAsDocButton_clicked();

    void on_addUserToolButton_clicked();

    void on_documentsTableView_clicked(const QModelIndex &index);

    void on_removeSelectionButton_clicked();

    void on_removeUserToolButton_clicked();

private:
    Ui::LoadSendDocForm *ui;
    QSqlRelationalTableModel *documentsModel_;
    QSqlRelationalTableModel *usersModel_;
    QSqlRelationalTableModel *docUserModel_;
};

#endif // LOADSENDDOCFORM_H
