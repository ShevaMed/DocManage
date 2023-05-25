#ifndef PUTSIGNATUREFORM_H
#define PUTSIGNATUREFORM_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class PutSignatureForm;
}

class PutSignatureForm : public QDialog
{
    Q_OBJECT

public:
    explicit PutSignatureForm(QWidget *parent = nullptr);
    ~PutSignatureForm();

private slots:
    void on_openDocButton_clicked();

    void on_saveCommentButton_clicked();

    void on_exitButton_clicked();

    void on_saveAsDocButton_clicked();

    void on_putSignatureButton_clicked();

    void on_documentsTableView_clicked(const QModelIndex &index);

private:
    Ui::PutSignatureForm *ui;
    QSqlRelationalTableModel *documentsModel_;
};

#endif // PUTSIGNATUREFORM_H
