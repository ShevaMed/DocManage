#include "loadsignatureform.h"
#include "ui_loadsignatureform.h"
#include "dbmanager.h"
#include "messagehandler.h"

#include <QFileDialog>
#include <QPixmap>
#include <QBuffer>

LoadSignatureForm::LoadSignatureForm(int signWidth, int signHeight,
                                     QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadSignatureForm),
    signWidth_(signWidth), signHeight_(signHeight),
    baseWindowWidth_(410), baseWindowHeight_(390), windowMinWidth_(800),
    zoomFactorSignInDoc_(2), signLabelHeight_(80),
    signLabelWidth_(signWidth * signLabelHeight_ / signHeight),
    signInDocLabelWidth_(signWidth * zoomFactorSignInDoc_)
{
    ui->setupUi(this);
    this->setMinimumWidth(windowMinWidth_);

    QPixmap docExamplePixmap(":/resources/images/docExamplePixmap.png");
    int docLabelWidth = docExamplePixmap.width();

    windowWidth_ = baseWindowWidth_ +
            std::max(signLabelWidth_, signInDocLabelWidth_ + docLabelWidth);
    this->resize(windowWidth_, baseWindowHeight_);

    ui->imageDocLabel->setPixmap(docExamplePixmap);
    ui->imageDocLabel->setStyleSheet("background-color: white;");
    ui->imageDocLabel->setMinimumSize(docLabelWidth, signLabelHeight_);
    ui->imageDocLabel->setMaximumSize(docLabelWidth, signLabelHeight_);

    ui->imageSignLabel->setScaledContents(true);
    ui->imageSignLabel->setStyleSheet("background-color: white;");
    ui->imageSignLabel->setMinimumSize(signLabelWidth_, signLabelHeight_);
    ui->imageSignLabel->setMaximumSize(signLabelWidth_, signLabelHeight_);

    ui->imageSignInDocLabel->setStyleSheet("background-color: white;");
    ui->imageSignInDocLabel->setMinimumSize(signInDocLabelWidth_, signLabelHeight_);
    ui->imageSignInDocLabel->setMaximumSize(signInDocLabelWidth_, signLabelHeight_);
}

LoadSignatureForm::~LoadSignatureForm()
{
    delete ui;
}

void LoadSignatureForm::setPixmapsInLabels()
{
    ui->imageSignLabel->setPixmap(signPixmap_);
    QPixmap scaledPixmap = signPixmap_.scaled(signWidth_ * zoomFactorSignInDoc_,
                                              signHeight_ * zoomFactorSignInDoc_,
                                              Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation);
    ui->imageSignInDocLabel->setPixmap(scaledPixmap);
}


void LoadSignatureForm::on_loadButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Обрати файл зображення підпису",
                                                "C:/Users/Public/Pictures/",
                                                "PNG Image (*.png);");
    if (!path.isEmpty()) {
        signPixmap_.load(path);
        QBitmap mask = signPixmap_.createMaskFromColor(Qt::white);
        signPixmap_.setMask(mask);
        this->setPixmapsInLabels();
    }
}


void LoadSignatureForm::on_checkBox_stateChanged(int arg1)
{
    if (!arg1)
        ui->imageSignLabel->setStyleSheet("");
    else
        ui->imageSignLabel->setStyleSheet("background-color: white;");
}


void LoadSignatureForm::on_exitButton_clicked()
{
    this->close();
}


void LoadSignatureForm::on_saveButton_clicked()
{
    if (signPixmap_.isNull()) {
        MessageHandler::showEmptyFileWarning(this);
        return;
    }

    QByteArray signature;
    QBuffer buffer(&signature);
    buffer.open(QIODevice::WriteOnly);
    signPixmap_.save(&buffer, "PNG");
    buffer.close();

    if (DBManager::updateUserSign(DBManager::userId, signature)) {
        MessageHandler::showSuccessInfo(this, "Підпис успішно збережено до бази даних!");
    }   
}


void LoadSignatureForm::on_viewButton_clicked()
{
    QByteArray signature = DBManager::selectSignFromUsers(DBManager::userId);
    if (signature.isEmpty()) {
        MessageHandler::showEmptySignWarning(this);
        return;
    }
    signPixmap_.loadFromData(signature);
    this->setPixmapsInLabels();
}


void LoadSignatureForm::on_deleteButton_clicked()
{
    if (DBManager::updateUserSign(DBManager::userId, QByteArray())) {
        MessageHandler::showSuccessInfo(this, "Підпис успішно видалено з бази даних!");
        signPixmap_ = QPixmap();
        ui->imageSignLabel->clear();
        ui->imageSignInDocLabel->clear();
    }
}

