/********************************************************************************
** Form generated from reading UI file 'loaddocform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADDOCFORM_H
#define UI_LOADDOCFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadDocForm
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *loadButton;
    QLabel *pathLabel;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QLineEdit *nameEdit;
    QCheckBox *setNameOfPathCheckBox;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QTextEdit *noteTextEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *exitButton;

    void setupUi(QDialog *LoadDocForm)
    {
        if (LoadDocForm->objectName().isEmpty())
            LoadDocForm->setObjectName("LoadDocForm");
        LoadDocForm->resize(450, 400);
        verticalLayout = new QVBoxLayout(LoadDocForm);
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName("verticalLayout");
        loadButton = new QPushButton(LoadDocForm);
        loadButton->setObjectName("loadButton");
        QFont font;
        font.setPointSize(13);
        loadButton->setFont(font);

        verticalLayout->addWidget(loadButton);

        pathLabel = new QLabel(LoadDocForm);
        pathLabel->setObjectName("pathLabel");
        pathLabel->setFont(font);
        pathLabel->setWordWrap(true);

        verticalLayout->addWidget(pathLabel);

        verticalSpacer_3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label = new QLabel(LoadDocForm);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(LoadDocForm);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setFont(font);

        verticalLayout->addWidget(nameEdit);

        setNameOfPathCheckBox = new QCheckBox(LoadDocForm);
        setNameOfPathCheckBox->setObjectName("setNameOfPathCheckBox");
        setNameOfPathCheckBox->setFont(font);

        verticalLayout->addWidget(setNameOfPathCheckBox);

        verticalSpacer_2 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(LoadDocForm);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_2);

        noteTextEdit = new QTextEdit(LoadDocForm);
        noteTextEdit->setObjectName("noteTextEdit");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(noteTextEdit->sizePolicy().hasHeightForWidth());
        noteTextEdit->setSizePolicy(sizePolicy);
        noteTextEdit->setFont(font);

        verticalLayout->addWidget(noteTextEdit);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(LoadDocForm);
        saveButton->setObjectName("saveButton");
        saveButton->setFont(font);

        horizontalLayout->addWidget(saveButton);

        exitButton = new QPushButton(LoadDocForm);
        exitButton->setObjectName("exitButton");
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoadDocForm);

        QMetaObject::connectSlotsByName(LoadDocForm);
    } // setupUi

    void retranslateUi(QDialog *LoadDocForm)
    {
        LoadDocForm->setWindowTitle(QCoreApplication::translate("LoadDocForm", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\265\320\275\320\275\321\217 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\321\203", nullptr));
        loadButton->setText(QCoreApplication::translate("LoadDocForm", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202 (\320\236\320\261\321\200\320\260\321\202\320\270 \321\204\320\260\320\271\320\273)", nullptr));
        pathLabel->setText(QCoreApplication::translate("LoadDocForm", "\320\250\320\273\321\217\321\205: ", nullptr));
        label->setText(QCoreApplication::translate("LoadDocForm", "\320\235\320\260\320\267\320\262\320\260 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        setNameOfPathCheckBox->setText(QCoreApplication::translate("LoadDocForm", "\320\227\320\260\321\201\321\202\320\276\321\201\321\203\320\262\320\260\321\202\320\270 \320\275\320\260\320\267\320\262\321\203 \321\204\320\260\320\271\320\273\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("LoadDocForm", "\320\237\321\200\320\270\320\274\321\226\321\202\320\272\320\260 \320\264\320\276 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260 (\320\275\320\265\320\276\320\261\320\276\320\262'\321\217\320\267\320\272\320\276\320\262\320\276)", nullptr));
        noteTextEdit->setHtml(QCoreApplication::translate("LoadDocForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        saveButton->setText(QCoreApplication::translate("LoadDocForm", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", nullptr));
        exitButton->setText(QCoreApplication::translate("LoadDocForm", "\320\222\320\270\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadDocForm: public Ui_LoadDocForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADDOCFORM_H
