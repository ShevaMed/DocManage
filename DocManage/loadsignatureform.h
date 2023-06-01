#ifndef LOADSIGNATUREFORM_H
#define LOADSIGNATUREFORM_H

#include <QDialog>

namespace Ui {
class LoadSignatureForm;
}

class LoadSignatureForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoadSignatureForm(int signWidth, int signHeight,
                               QWidget *parent = nullptr);
    ~LoadSignatureForm();

private:
    void setPixmapsInLabels();

private slots:
    void on_loadButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_exitButton_clicked();

    void on_saveButton_clicked();

    void on_viewButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::LoadSignatureForm *ui;
    const int signWidth_, signHeight_;
    const int baseWindowWidth_, baseWindowHeight_;
    const int windowMinWidth_;
    const int zoomFactorSignInDoc_;
    const int signLabelHeight_, signLabelWidth_;
    const int signInDocLabelWidth_;
    int windowWidth_;
    QPixmap signPixmap_;
};

#endif // LOADSIGNATUREFORM_H
