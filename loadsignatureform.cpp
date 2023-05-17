#include "loadsignatureform.h"
#include "ui_loadsignatureform.h"

#include <QFileDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPixmap>
#include <QBuffer>

LoadSignatureForm::LoadSignatureForm(int userId, int signWidth, int signHeight,
                                     QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadSignatureForm),
    userId_(userId), signWidth_(signWidth), signHeight_(signHeight),
    baseWindowWidth_(410), baseWindowHeight_(390), windowMinWidth_(770),
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

    ui->imageSignLabel->setScaledContents(true);
    ui->imageSignLabel->setStyleSheet("background-color: white;");
    ui->imageSignLabel->setMinimumSize(signLabelWidth_, signLabelHeight_);
    ui->imageSignLabel->setMaximumSize(signLabelWidth_, signLabelHeight_);

    ui->imageSignInDocLabel->setStyleSheet("background-color: white;");
    ui->imageSignInDocLabel->setMinimumSize(signInDocLabelWidth_, signLabelHeight_);
    ui->imageSignInDocLabel->setMaximumSize(signInDocLabelWidth_, signLabelHeight_);

    ui->imageDocLabel->setPixmap(docExamplePixmap);
    ui->imageDocLabel->setStyleSheet("background-color: white;");
    ui->imageDocLabel->setMinimumSize(docLabelWidth, signLabelHeight_);
    ui->imageDocLabel->setMaximumSize(docLabelWidth, signLabelHeight_);
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
    if (!path.isNull()) {
        signPixmap_.load(path);
        QBitmap mask = signPixmap_.createMaskFromColor(Qt::white);
        signPixmap_.setMask(mask);
        setPixmapsInLabels();
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
    close();
}


void LoadSignatureForm::on_saveButton_clicked()
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    signPixmap_.save(&buffer, "PNG");
    buffer.close();

    QSqlQuery query;
    query.prepare("UPDATE users SET signature = :sign WHERE id = :id");
    query.bindValue(":sign", byteArray);
    query.bindValue(":id", userId_);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка збереження підпису",
                                  "Не вдалося зберегти підпис у базу даних. "
                                  "Перевірте налаштування підключення або змініть файл підпису!");
        return;
    }

    QMessageBox::information(this, "Успіх", "Підпис збережено до бази даних!");
}


void LoadSignatureForm::on_viewButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT signature FROM users WHERE id = :id");
    query.bindValue(":id", userId_);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка скачування підпису",
                                  "Не вдалося скачати підпис із бази даних. "
                                  "Перевірте налаштування підключення!");
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Помилка скачування підпису",
                                  "Не вдалося скачати підпис із бази даних. "
                                  "Ви ще не зберігали свій підпис!");
        return;
    }

    QByteArray byteArray = query.value("signature").toByteArray();
    signPixmap_.loadFromData(byteArray);
    setPixmapsInLabels();
}

