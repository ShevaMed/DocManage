#include "docoperations.h"
#include "messagehandler.h"

#include <QTemporaryFile>
#include <QFileDialog>
#include <QAxObject>

DocOperations::DocOperations()
{

}

void DocOperations::saveAs(QDialog *form, QString documentName, const QByteArray& content)
{
    QString path = QFileDialog::getSaveFileName(form, "Зберегти документ",
                                                    "C:/Users/Public/Documents/" + documentName,
                                                    "MS Word Document (*.docx *.doc);");
    if (!path.isEmpty()) {
        QFile document(path);
        if (!document.open(QIODevice::WriteOnly)) {
            MessageHandler::showOpenFileWarning(form);
            return;
        }
        document.write(content);
        document.close();
        MessageHandler::showSuccessInfo(form, "Документ успішно збережено!");
    }
}

void DocOperations::open(QDialog *form, const QByteArray& content)
{
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

QByteArray DocOperations::putSignature(QDialog *form, QString documentName,
                                       const QByteArray& content, const QByteArray& signature,
                                       QString textForPutSignature, int signWidth, int signHeight)
{
    QString path = QFileDialog::getSaveFileName(form, "Зберегти документ для встановлення підпису",
                                                    "C:/Users/Public/Documents/" + documentName,
                                                    "MS Word Document (*.docx *.doc);");
    if (path.isEmpty()) {
        return {};
    }

    QFile docFile(path);
    if (!docFile.open(QIODevice::WriteOnly)) {
         MessageHandler::showOpenFileWarning(form);
         return {};
    }
    docFile.write(content);
    docFile.close();

    QTemporaryFile tempSignatureFile;
    tempSignatureFile.open();
    tempSignatureFile.write(signature);
    tempSignatureFile.close();

    // Create a new Word application
    QAxObject* wordApp = new QAxObject("Word.Application");

    // Set the visibility to false so that Word doesn't show up
    wordApp->setProperty("Visible", false);

    // Open the document
    QAxObject* document = wordApp->querySubObject("Documents");
    document = document->querySubObject("Open(const QString&, bool)", path, false);

    // Get the selection of all document
    QAxObject* selection = wordApp->querySubObject("Selection");

    // Set the MatchCase option to true for case sensitivity
    QAxObject* find = selection->querySubObject("Find");
    find->setProperty("MatchCase", true);

    // Search for the text
    find->dynamicCall("Execute(const QString&)", textForPutSignature);

    // Get left and top of selection relative to text border
    int leftSelection = selection->dynamicCall("Information(wdHorizontalPositionRelativeToTextBoundary)").toInt();
    int topSelection = selection->dynamicCall("Information(wdVerticalPositionRelativeToTextBoundary)").toInt();

    // Calculate left and top to insert picture into document
    int leftToInsert = leftSelection - signWidth - 5;
    int topToInsert = topSelection - (signHeight - 12) / 4;

    // Insert an image
    QAxObject* shape = document->querySubObject("Shapes");
    shape = shape->querySubObject("AddPicture(const QString&, bool, bool, int, int, int, int)",
                                  tempSignatureFile.fileName(), false, true,
                                  leftToInsert, topToInsert, signWidth, signHeight);

    // Save the document
    document->dynamicCall("Save()");

    // Close the document and application
    document->dynamicCall("Close()");
    wordApp->dynamicCall("Quit()");

    if (!docFile.open(QIODevice::ReadOnly)) {
         MessageHandler::showOpenFileWarning(form);
         return {};
    }
    QByteArray docFileWithSignature = docFile.readAll();
    docFile.close();
    return docFileWithSignature;
}
