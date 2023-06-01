#ifndef LOADDOCFORM_H
#define LOADDOCFORM_H

#include <QDialog>

namespace Ui {
class LoadDocForm;
}

class LoadDocForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoadDocForm(QWidget *parent = nullptr);
    explicit LoadDocForm(int documentId, QString documentName,
                         QString documentNote, QWidget *parent = nullptr);
    ~LoadDocForm();

private:
    explicit LoadDocForm(int documentId, QWidget *parent);

private slots:
    void on_exitButton_clicked();

    void on_setNameOfPathCheckBox_stateChanged(int arg1);

    void on_loadButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::LoadDocForm *ui;
    const int documentId_;
    QString path_;
};

#endif // LOADDOCFORM_H
