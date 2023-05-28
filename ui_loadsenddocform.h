/********************************************************************************
** Form generated from reading UI file 'loadsenddocform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSENDDOCFORM_H
#define UI_LOADSENDDOCFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadSendDocForm
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QTableView *documentsTableView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *loadDocButton;
    QPushButton *editDocButton;
    QPushButton *openDocButton;
    QPushButton *saveAsDocButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableView *usersTableView;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QToolButton *addUserToolButton;
    QSpacerItem *verticalSpacer_3;
    QToolButton *removeUserToolButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTableView *docUserTableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *removeSelectionButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;

    void setupUi(QDialog *LoadSendDocForm)
    {
        if (LoadSendDocForm->objectName().isEmpty())
            LoadSendDocForm->setObjectName("LoadSendDocForm");
        LoadSendDocForm->resize(1024, 576);
        verticalLayout_6 = new QVBoxLayout(LoadSendDocForm);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(LoadSendDocForm);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(13);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_4->addWidget(label_3);

        documentsTableView = new QTableView(LoadSendDocForm);
        documentsTableView->setObjectName("documentsTableView");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(documentsTableView->sizePolicy().hasHeightForWidth());
        documentsTableView->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(11);
        documentsTableView->setFont(font1);
        documentsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        documentsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_4->addWidget(documentsTableView);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        loadDocButton = new QPushButton(LoadSendDocForm);
        loadDocButton->setObjectName("loadDocButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loadDocButton->sizePolicy().hasHeightForWidth());
        loadDocButton->setSizePolicy(sizePolicy1);
        loadDocButton->setFont(font);

        verticalLayout->addWidget(loadDocButton);

        editDocButton = new QPushButton(LoadSendDocForm);
        editDocButton->setObjectName("editDocButton");
        sizePolicy1.setHeightForWidth(editDocButton->sizePolicy().hasHeightForWidth());
        editDocButton->setSizePolicy(sizePolicy1);
        editDocButton->setFont(font);

        verticalLayout->addWidget(editDocButton);

        openDocButton = new QPushButton(LoadSendDocForm);
        openDocButton->setObjectName("openDocButton");
        sizePolicy1.setHeightForWidth(openDocButton->sizePolicy().hasHeightForWidth());
        openDocButton->setSizePolicy(sizePolicy1);
        openDocButton->setFont(font);

        verticalLayout->addWidget(openDocButton);

        saveAsDocButton = new QPushButton(LoadSendDocForm);
        saveAsDocButton->setObjectName("saveAsDocButton");
        sizePolicy1.setHeightForWidth(saveAsDocButton->sizePolicy().hasHeightForWidth());
        saveAsDocButton->setSizePolicy(sizePolicy1);
        saveAsDocButton->setFont(font);

        verticalLayout->addWidget(saveAsDocButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(LoadSendDocForm);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label);

        usersTableView = new QTableView(LoadSendDocForm);
        usersTableView->setObjectName("usersTableView");
        sizePolicy.setHeightForWidth(usersTableView->sizePolicy().hasHeightForWidth());
        usersTableView->setSizePolicy(sizePolicy);
        usersTableView->setFont(font1);
        usersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        usersTableView->setTabKeyNavigation(true);
        usersTableView->setAlternatingRowColors(false);
        usersTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(usersTableView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        addUserToolButton = new QToolButton(LoadSendDocForm);
        addUserToolButton->setObjectName("addUserToolButton");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addUserToolButton->sizePolicy().hasHeightForWidth());
        addUserToolButton->setSizePolicy(sizePolicy2);
        addUserToolButton->setIconSize(QSize(25, 25));
        addUserToolButton->setArrowType(Qt::RightArrow);

        verticalLayout_5->addWidget(addUserToolButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        removeUserToolButton = new QToolButton(LoadSendDocForm);
        removeUserToolButton->setObjectName("removeUserToolButton");
        sizePolicy2.setHeightForWidth(removeUserToolButton->sizePolicy().hasHeightForWidth());
        removeUserToolButton->setSizePolicy(sizePolicy2);
        removeUserToolButton->setIconSize(QSize(25, 25));
        removeUserToolButton->setArrowType(Qt::LeftArrow);

        verticalLayout_5->addWidget(removeUserToolButton);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(LoadSendDocForm);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_3->addWidget(label_2);

        docUserTableView = new QTableView(LoadSendDocForm);
        docUserTableView->setObjectName("docUserTableView");
        sizePolicy.setHeightForWidth(docUserTableView->sizePolicy().hasHeightForWidth());
        docUserTableView->setSizePolicy(sizePolicy);
        docUserTableView->setFont(font1);
        docUserTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        docUserTableView->setAlternatingRowColors(false);
        docUserTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(docUserTableView);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        removeSelectionButton = new QPushButton(LoadSendDocForm);
        removeSelectionButton->setObjectName("removeSelectionButton");
        sizePolicy1.setHeightForWidth(removeSelectionButton->sizePolicy().hasHeightForWidth());
        removeSelectionButton->setSizePolicy(sizePolicy1);
        removeSelectionButton->setFont(font);

        horizontalLayout_3->addWidget(removeSelectionButton);

        horizontalSpacer = new QSpacerItem(598, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exitButton = new QPushButton(LoadSendDocForm);
        exitButton->setObjectName("exitButton");
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        exitButton->setFont(font);

        horizontalLayout_3->addWidget(exitButton);


        verticalLayout_6->addLayout(horizontalLayout_3);


        retranslateUi(LoadSendDocForm);

        QMetaObject::connectSlotsByName(LoadSendDocForm);
    } // setupUi

    void retranslateUi(QDialog *LoadSendDocForm)
    {
        LoadSendDocForm->setWindowTitle(QCoreApplication::translate("LoadSendDocForm", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("LoadSendDocForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\321\226\320\262", nullptr));
        loadDocButton->setText(QCoreApplication::translate("LoadSendDocForm", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", nullptr));
        editDocButton->setText(QCoreApplication::translate("LoadSendDocForm", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", nullptr));
        openDocButton->setText(QCoreApplication::translate("LoadSendDocForm", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", nullptr));
        saveAsDocButton->setText(QCoreApplication::translate("LoadSendDocForm", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \321\217\320\272", nullptr));
        label->setText(QCoreApplication::translate("LoadSendDocForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207\321\226\320\262", nullptr));
        addUserToolButton->setText(QCoreApplication::translate("LoadSendDocForm", "...", nullptr));
        removeUserToolButton->setText(QCoreApplication::translate("LoadSendDocForm", "...", nullptr));
        label_2->setText(QCoreApplication::translate("LoadSendDocForm", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\321\226\320\264\320\277\320\270\321\201\320\260\320\275\321\202\321\226\320\262 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        removeSelectionButton->setText(QCoreApplication::translate("LoadSendDocForm", "\320\227\320\275\321\217\321\202\320\270 \320\262\320\270\320\264\321\226\320\273\320\265\320\275\320\275\321\217", nullptr));
        exitButton->setText(QCoreApplication::translate("LoadSendDocForm", "\320\222\320\270\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadSendDocForm: public Ui_LoadSendDocForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSENDDOCFORM_H
