#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QWidget>

class MessageHandler
{
public:
    MessageHandler();

    static void showDBQueryError(QWidget *parent, QString queryError);
    static void showOpenFileError(QWidget *parent, QString fileName);
    static void showOpenDatabaseError(QWidget *parent, QString databaseError);
    static void showEmptySignWarning(QWidget *parent);
    static void showEmptyFileWarning(QWidget *parent);
    static void showEmptyEditWarning(QWidget *parent, QString whomIsEmpty);
    static void showOpenFileWarning(QWidget *parent);
    static void showInvalidIndexWarning(QWidget *parent, QString whomIsSelected);
    static void showSameAccountWarning(QWidget *parent);
    static void showNotExistAccountWarning(QWidget *parent);
    static void showWrongPasswordWarning(QWidget *parent);
    static void showInvalidPutSignWarning(QWidget *parent);
    static void showSuccessInfo(QWidget *parent, QString message);
    static bool replyRewriteDocument(QWidget *parent);
};

#endif // MESSAGEHANDLER_H
