#include "settingsform.h"
#include "ui_settingsform.h"
#include "dbmanager.h"
#include "messagehandler.h"

#include <QSqlRecord>
#include <QSqlField>

SettingsForm::SettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsForm),
    settingsModel_(DBManager::instance().getSettingsModel())
{
    ui->setupUi(this);
    this->resize(550, 330);

    ui->settingsTableView->setModel(settingsModel_);
    ui->settingsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

void SettingsForm::on_settingsTableView_clicked(const QModelIndex &index)
{
    QString value = settingsModel_->record(index.row()).field("value_").value().toString();
    ui->valueEdit->setText(value);
}


void SettingsForm::on_saveButton_clicked()
{
    int currRow = ui->settingsTableView->currentIndex().row();
    if (currRow < 0) {
        MessageHandler::showInvalidIndexWarning(this, "Параметр");
        return;
    }

    int settingId = settingsModel_->record(currRow).field("id").value().toInt();
    if (DBManager::updateSettings(settingId, ui->valueEdit->text())) {
        MessageHandler::showSuccessInfo(this, "Значення параметру успішно збережено!");
    }
}


void SettingsForm::on_exitButton_clicked()
{
    this->close();
}

