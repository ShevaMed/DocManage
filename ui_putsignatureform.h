/********************************************************************************
** Form generated from reading UI file 'putsignatureform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUTSIGNATUREFORM_H
#define UI_PUTSIGNATUREFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PutSignatureForm
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *documentsTableView;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *signedCheckBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPlainTextEdit *noteTextEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *putSignatureButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *openDocButton;
    QPushButton *saveAsDocButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPlainTextEdit *userNoteTextEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveCommentButton;
    QPushButton *exitButton;

    void setupUi(QDialog *PutSignatureForm)
    {
        if (PutSignatureForm->objectName().isEmpty())
            PutSignatureForm->setObjectName("PutSignatureForm");
        PutSignatureForm->resize(800, 450);
        verticalLayout_6 = new QVBoxLayout(PutSignatureForm);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(PutSignatureForm);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label);

        documentsTableView = new QTableView(PutSignatureForm);
        documentsTableView->setObjectName("documentsTableView");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(documentsTableView->sizePolicy().hasHeightForWidth());
        documentsTableView->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(11);
        documentsTableView->setFont(font1);
        documentsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        documentsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(documentsTableView);


        verticalLayout_6->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName("verticalLayout_5");
        signedCheckBox = new QCheckBox(PutSignatureForm);
        signedCheckBox->setObjectName("signedCheckBox");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(signedCheckBox->sizePolicy().hasHeightForWidth());
        signedCheckBox->setSizePolicy(sizePolicy1);
        signedCheckBox->setFont(font);

        verticalLayout_5->addWidget(signedCheckBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(PutSignatureForm);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label_2);

        noteTextEdit = new QPlainTextEdit(PutSignatureForm);
        noteTextEdit->setObjectName("noteTextEdit");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(noteTextEdit->sizePolicy().hasHeightForWidth());
        noteTextEdit->setSizePolicy(sizePolicy3);
        noteTextEdit->setMinimumSize(QSize(0, 0));
        noteTextEdit->setMaximumSize(QSize(16777215, 90));
        noteTextEdit->setFont(font);
        noteTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(noteTextEdit);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        putSignatureButton = new QPushButton(PutSignatureForm);
        putSignatureButton->setObjectName("putSignatureButton");
        sizePolicy2.setHeightForWidth(putSignatureButton->sizePolicy().hasHeightForWidth());
        putSignatureButton->setSizePolicy(sizePolicy2);
        putSignatureButton->setMinimumSize(QSize(230, 0));
        putSignatureButton->setFont(font);

        horizontalLayout_3->addWidget(putSignatureButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        openDocButton = new QPushButton(PutSignatureForm);
        openDocButton->setObjectName("openDocButton");
        sizePolicy1.setHeightForWidth(openDocButton->sizePolicy().hasHeightForWidth());
        openDocButton->setSizePolicy(sizePolicy1);
        openDocButton->setFont(font);

        horizontalLayout->addWidget(openDocButton);

        saveAsDocButton = new QPushButton(PutSignatureForm);
        saveAsDocButton->setObjectName("saveAsDocButton");
        sizePolicy1.setHeightForWidth(saveAsDocButton->sizePolicy().hasHeightForWidth());
        saveAsDocButton->setSizePolicy(sizePolicy1);
        saveAsDocButton->setFont(font);

        horizontalLayout->addWidget(saveAsDocButton);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(PutSignatureForm);
        label_3->setObjectName("label_3");
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_3->setWordWrap(true);

        verticalLayout_3->addWidget(label_3);

        userNoteTextEdit = new QPlainTextEdit(PutSignatureForm);
        userNoteTextEdit->setObjectName("userNoteTextEdit");
        sizePolicy3.setHeightForWidth(userNoteTextEdit->sizePolicy().hasHeightForWidth());
        userNoteTextEdit->setSizePolicy(sizePolicy3);
        userNoteTextEdit->setMinimumSize(QSize(0, 0));
        userNoteTextEdit->setMaximumSize(QSize(16777215, 90));
        userNoteTextEdit->setFont(font);

        verticalLayout_3->addWidget(userNoteTextEdit);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        saveCommentButton = new QPushButton(PutSignatureForm);
        saveCommentButton->setObjectName("saveCommentButton");
        sizePolicy1.setHeightForWidth(saveCommentButton->sizePolicy().hasHeightForWidth());
        saveCommentButton->setSizePolicy(sizePolicy1);
        saveCommentButton->setFont(font);

        horizontalLayout_2->addWidget(saveCommentButton);

        exitButton = new QPushButton(PutSignatureForm);
        exitButton->setObjectName("exitButton");
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        exitButton->setFont(font);

        horizontalLayout_2->addWidget(exitButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_4);


        retranslateUi(PutSignatureForm);

        QMetaObject::connectSlotsByName(PutSignatureForm);
    } // setupUi

    void retranslateUi(QDialog *PutSignatureForm)
    {
        PutSignatureForm->setWindowTitle(QCoreApplication::translate("PutSignatureForm", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PutSignatureForm", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\226 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\270", nullptr));
        signedCheckBox->setText(QCoreApplication::translate("PutSignatureForm", "\320\237\320\276\320\272\320\260\320\267\321\203\320\262\320\260\321\202\320\270 \321\202\321\226\320\273\321\214\320\272\320\270 \320\275\320\265\320\277\321\226\320\264\320\277\320\270\321\201\320\260\320\275\321\226 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("PutSignatureForm", "\320\237\321\200\320\270\320\274\321\226\321\202\320\272\320\260 \320\264\320\276 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        putSignatureButton->setText(QCoreApplication::translate("PutSignatureForm", "\320\237\320\276\321\201\321\202\320\260\320\262\320\270\321\202\320\270 \320\277\321\226\320\264\320\277\320\270\321\201", nullptr));
        openDocButton->setText(QCoreApplication::translate("PutSignatureForm", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", nullptr));
        saveAsDocButton->setText(QCoreApplication::translate("PutSignatureForm", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \321\217\320\272", nullptr));
        label_3->setText(QCoreApplication::translate("PutSignatureForm", "\320\232\320\276\320\274\320\265\320\275\321\202\320\260\321\200 \320\264\320\276 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260 (\320\275\320\265\320\276\320\261\320\276\320\262'\321\217\320\267\320\272\320\276\320\262\320\276)", nullptr));
        saveCommentButton->setText(QCoreApplication::translate("PutSignatureForm", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\272\320\276\320\274\320\265\320\275\321\202\320\260\321\200", nullptr));
        exitButton->setText(QCoreApplication::translate("PutSignatureForm", "\320\222\320\270\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PutSignatureForm: public Ui_PutSignatureForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUTSIGNATUREFORM_H
