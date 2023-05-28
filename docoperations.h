#ifndef DOCOPERATIONS_H
#define DOCOPERATIONS_H

#include <QDialog>

class DocOperations
{
public:
    DocOperations();

    static void saveAs(QDialog *form, QString documentName, const QByteArray& content);
    static void open(QDialog *form, const QByteArray& content);
    static QByteArray putSignature(QDialog *form, const QByteArray& content,
                                   const QByteArray& signature, QString textForPutSignature,
                                   int signWidth, int signHeight);
};

#endif // DOCOPERATIONS_H
