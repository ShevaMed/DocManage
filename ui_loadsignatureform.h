/********************************************************************************
** Form generated from reading UI file 'loadsignatureform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSIGNATUREFORM_H
#define UI_LOADSIGNATUREFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadSignatureForm
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *imageSignLabel;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *imageSignInDocLabel;
    QLabel *imageDocLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *deleteButton;
    QPushButton *viewButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *loadButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveButton;
    QPushButton *exitButton;

    void setupUi(QWidget *LoadSignatureForm)
    {
        if (LoadSignatureForm->objectName().isEmpty())
            LoadSignatureForm->setObjectName("LoadSignatureForm");
        LoadSignatureForm->resize(784, 390);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoadSignatureForm->sizePolicy().hasHeightForWidth());
        LoadSignatureForm->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(LoadSignatureForm);
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(LoadSignatureForm);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        imageSignLabel = new QLabel(LoadSignatureForm);
        imageSignLabel->setObjectName("imageSignLabel");
        sizePolicy.setHeightForWidth(imageSignLabel->sizePolicy().hasHeightForWidth());
        imageSignLabel->setSizePolicy(sizePolicy);
        imageSignLabel->setMinimumSize(QSize(270, 80));
        imageSignLabel->setMaximumSize(QSize(270, 80));
        imageSignLabel->setStyleSheet(QString::fromUtf8("background-color: white;"));
        imageSignLabel->setScaledContents(false);
        imageSignLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(imageSignLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        checkBox = new QCheckBox(LoadSignatureForm);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        label_3 = new QLabel(LoadSignatureForm);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        imageSignInDocLabel = new QLabel(LoadSignatureForm);
        imageSignInDocLabel->setObjectName("imageSignInDocLabel");
        sizePolicy.setHeightForWidth(imageSignInDocLabel->sizePolicy().hasHeightForWidth());
        imageSignInDocLabel->setSizePolicy(sizePolicy);
        imageSignInDocLabel->setMinimumSize(QSize(154, 80));
        imageSignInDocLabel->setMaximumSize(QSize(154, 80));
        imageSignInDocLabel->setStyleSheet(QString::fromUtf8("background-color: white;"));
        imageSignInDocLabel->setLineWidth(0);
        imageSignInDocLabel->setScaledContents(false);
        imageSignInDocLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(imageSignInDocLabel);

        imageDocLabel = new QLabel(LoadSignatureForm);
        imageDocLabel->setObjectName("imageDocLabel");
        imageDocLabel->setMinimumSize(QSize(210, 80));
        imageDocLabel->setMaximumSize(QSize(210, 80));
        imageDocLabel->setStyleSheet(QString::fromUtf8("background-color: white;"));
        imageDocLabel->setLineWidth(0);
        imageDocLabel->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/docExamplePixmap.png")));
        imageDocLabel->setScaledContents(false);

        horizontalLayout->addWidget(imageDocLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(363, 23, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        deleteButton = new QPushButton(LoadSignatureForm);
        deleteButton->setObjectName("deleteButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy2);
        deleteButton->setFont(font);

        horizontalLayout_4->addWidget(deleteButton);

        viewButton = new QPushButton(LoadSignatureForm);
        viewButton->setObjectName("viewButton");
        sizePolicy2.setHeightForWidth(viewButton->sizePolicy().hasHeightForWidth());
        viewButton->setSizePolicy(sizePolicy2);
        viewButton->setFont(font);

        horizontalLayout_4->addWidget(viewButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(7);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(LoadSignatureForm);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setWordWrap(true);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        loadButton = new QPushButton(LoadSignatureForm);
        loadButton->setObjectName("loadButton");
        sizePolicy2.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy2);
        loadButton->setFont(font);

        verticalLayout_2->addWidget(loadButton);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        saveButton = new QPushButton(LoadSignatureForm);
        saveButton->setObjectName("saveButton");
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);
        saveButton->setFont(font);

        horizontalLayout_3->addWidget(saveButton);

        exitButton = new QPushButton(LoadSignatureForm);
        exitButton->setObjectName("exitButton");
        sizePolicy2.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy2);
        exitButton->setFont(font);

        horizontalLayout_3->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(LoadSignatureForm);

        QMetaObject::connectSlotsByName(LoadSignatureForm);
    } // setupUi

    void retranslateUi(QWidget *LoadSignatureForm)
    {
        LoadSignatureForm->setWindowTitle(QCoreApplication::translate("LoadSignatureForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoadSignatureForm", "\320\227\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \320\277\321\226\320\264\320\277\320\270\321\201\321\203, \321\217\320\272\320\265 \321\200\320\276\320\267\321\202\321\217\320\263\320\275\321\203\321\202\320\265 \320\264\320\276 \320\275\320\265\320\276\320\261\321\205\321\226\320\264\320\275\320\270\321\205 \320\277\321\200\320\276\320\277\320\276\321\200\321\206\321\226\320\271", nullptr));
        imageSignLabel->setText(QString());
        checkBox->setText(QCoreApplication::translate("LoadSignatureForm", "\320\221\321\226\320\273\320\270\320\271 \321\204\320\276\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("LoadSignatureForm", "\320\237\321\200\320\270\320\261\320\273\320\270\320\267\320\275\320\270\320\271 \320\262\320\270\320\263\320\273\321\217\320\264 \320\277\321\226\320\264\320\277\320\270\321\201\321\203 \321\203 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\321\226", nullptr));
        imageSignInDocLabel->setText(QString());
        imageDocLabel->setText(QString());
        deleteButton->setText(QCoreApplication::translate("LoadSignatureForm", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\277\321\226\320\264\320\277\320\270\321\201", nullptr));
        viewButton->setText(QCoreApplication::translate("LoadSignatureForm", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\275\321\203\321\202\320\270 \320\277\321\226\320\264\320\277\320\270\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("LoadSignatureForm", "<html><head/><body><p>\320\237\321\226\320\264\320\277\320\270\321\201 \320\277\320\276\320\262\320\270\320\275\320\265\320\275 \320\261\321\203\321\202\320\270 \321\207\320\276\321\200\320\275\320\276\320\263\320\276 \320\272\320\276\320\273\321\214\320\276\321\200\321\203 \320\275\320\260 \320\261\321\226\320\273\320\276\320\274\321\203 \321\204\320\276\320\275\321\226. </p><p>\320\227\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \320\277\321\226\320\264\320\277\320\270\321\201\321\203 \320\277\320\276\320\262\320\270\320\275\320\275\320\276 \320\261\321\203\321\202\320\270 \320\276\320\261\321\200\321\226\320\267\320\260\320\275\320\276 \320\277\320\276 \320\263\321\200\320\260\320\275\320\270\321\206\321\217\320\274 \320\277\321\226\320\264\320\277\320\270\321\201\321\203 \321\202\320\260 \320\274\320\260\321\202\320\270 \320\277\321\200\320\276\320\277\320\276\321\200\321\206\321\226\321\227, \320\277\321\200\320\270\320\261\320\273\320\270\320\267\320\275\320\276 3 : 1 (3 \321\210"
                        "\320\270\321\200\320\270\320\275\320\270 \320\264\320\276 1 \320\262\320\270\321\201\320\276\321\202\320\270). </p><p>\320\244\320\260\320\271\320\273 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \320\277\321\226\320\264\320\277\320\270\321\201\321\203 \320\277\320\276\320\262\320\270\320\275\320\265\320\275 \320\261\321\203\321\202\320\270 \321\204\320\276\321\200\320\274\320\260\321\202\321\203 (.png) \321\202\320\260 \321\200\320\276\320\267\320\274\321\226\321\200\321\203 \320\275\320\265 \320\261\321\226\320\273\321\214\321\210\320\265 50 \320\232\320\221. </p><p>\320\222\320\270\320\264\320\260\320\273\321\217\321\202\320\270 \320\261\321\226\320\273\320\270\320\271 \321\204\320\276\320\275 \320\275\320\265\320\276\320\261\320\276\320\262'\321\217\320\267\320\272\320\276\320\262\320\276, \320\277\321\200\320\270 \320\267\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\265\320\275\320\275\321\226 \320\262\321\226\320\275 \320\262\320\270\320\264\320\260\320\273"
                        "\321\217\321\224\321\202\321\214\321\201\321\217 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\275\320\276.</p></body></html>", nullptr));
        loadButton->setText(QCoreApplication::translate("LoadSignatureForm", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\277\321\226\320\264\320\277\320\270\321\201 (\320\236\320\261\321\200\320\260\321\202\320\270 \321\204\320\260\320\271\320\273)", nullptr));
        saveButton->setText(QCoreApplication::translate("LoadSignatureForm", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\277\321\226\320\264\320\277\320\270\321\201", nullptr));
        exitButton->setText(QCoreApplication::translate("LoadSignatureForm", "\320\222\320\270\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadSignatureForm: public Ui_LoadSignatureForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSIGNATUREFORM_H
