/********************************************************************************
** Form generated from reading UI file 'settingsform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSFORM_H
#define UI_SETTINGSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *settingsTableView;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *valueEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *exitButton;

    void setupUi(QDialog *SettingsForm)
    {
        if (SettingsForm->objectName().isEmpty())
            SettingsForm->setObjectName("SettingsForm");
        SettingsForm->resize(550, 330);
        verticalLayout_2 = new QVBoxLayout(SettingsForm);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(SettingsForm);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        verticalLayout->addWidget(label);

        settingsTableView = new QTableView(SettingsForm);
        settingsTableView->setObjectName("settingsTableView");
        QFont font1;
        font1.setPointSize(11);
        settingsTableView->setFont(font1);

        verticalLayout->addWidget(settingsTableView);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        label_2 = new QLabel(SettingsForm);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        valueEdit = new QLineEdit(SettingsForm);
        valueEdit->setObjectName("valueEdit");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(valueEdit->sizePolicy().hasHeightForWidth());
        valueEdit->setSizePolicy(sizePolicy);
        valueEdit->setFont(font);

        horizontalLayout->addWidget(valueEdit);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(SettingsForm);
        saveButton->setObjectName("saveButton");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);
        saveButton->setFont(font);

        horizontalLayout->addWidget(saveButton);

        exitButton = new QPushButton(SettingsForm);
        exitButton->setObjectName("exitButton");
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(SettingsForm);

        QMetaObject::connectSlotsByName(SettingsForm);
    } // setupUi

    void retranslateUi(QDialog *SettingsForm)
    {
        SettingsForm->setWindowTitle(QCoreApplication::translate("SettingsForm", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SettingsForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\226\320\262", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsForm", "\320\227\320\275\320\260\321\207\320\265\320\275\320\275\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\203", nullptr));
        saveButton->setText(QCoreApplication::translate("SettingsForm", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", nullptr));
        exitButton->setText(QCoreApplication::translate("SettingsForm", "\320\222\320\270\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsForm: public Ui_SettingsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSFORM_H
