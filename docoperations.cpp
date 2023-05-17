#include "docoperations.h"

#include <QSqlRecord>
#include <QSqlField>
#include <QMessageBox>
#include <QTemporaryFile>
#include <QFileDialog>
#include <QAxObject>

DocOperations::DocOperations()
{

}

void DocOperations::saveAs(QDialog *form, QSqlRelationalTableModel *model, int row)
{
    QString docName = model->record(row).field("document_name").value().toString();

    QString path = QFileDialog::getSaveFileName(form, "Зберегти документ",
                                                    "C:/Users/Public/Documents/" + docName,
                                                    "MS Word Document (*.docx *.doc);");
    if (!path.isEmpty()) {
        QFile document(path);
        if (!document.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(form, "Помилка відкриття", "Не вдалося відкрити файл.");
            return;
        }

        QByteArray content = model->record(row).field("content").value().toByteArray();
        document.write(content);
        document.close();
        QMessageBox::information(form, "Успіх", "Документ успішно збережено!");
    }
}

void DocOperations::open(QDialog *form, QSqlRelationalTableModel *model, int row)
{
    QByteArray content = model->record(row).field("content").value().toByteArray();

    QTemporaryFile tempFile;
    tempFile.open();
    tempFile.write(content);
    tempFile.close();

    // Create a new Word application
    QAxObject* wordApp = new QAxObject("Word.Application");

    // Set the visibility to false so that Word doesn't show up
    wordApp->setProperty("Visible", true);

    // Open the document
    QAxObject* document = wordApp->querySubObject("Documents");
    document = document->querySubObject("Open(const QString&)", tempFile.fileName());

    document->clear();
    wordApp->clear();
}

int DocOperations::getRowIndex(QDialog *form, QTableView *table, QString whomIsSelected)
{
    if (!table->currentIndex().isValid()) {
        QMessageBox::warning(form, whomIsSelected + " не обрано",
                                  "Виберіть " + whomIsSelected + " у таблиці!");
        return -1;
    }
    return table->currentIndex().row();
}
