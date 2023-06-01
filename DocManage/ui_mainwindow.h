/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *loginTab;
    QVBoxLayout *verticalLayout_18;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QLabel *label;
    QLineEdit *loginFnameEdit;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_2;
    QLineEdit *loginLnameEdit;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_3;
    QLineEdit *loginPasswordEdit;
    QSpacerItem *verticalSpacer_3;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_17;
    QLabel *loginImageLabel;
    QSpacerItem *verticalSpacer_7;
    QPushButton *loginExitButton;
    QWidget *signupTab;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_10;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLineEdit *signupFnameEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLineEdit *signupLnameEdit;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLineEdit *signupPasswordEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *signupManageCodeLabel;
    QComboBox *signupTypeAccComboBox;
    QSpacerItem *signupCodeHorizontalSpacer;
    QLineEdit *signupManageCodeEdit;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QLineEdit *signupJobTitleEdit;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QLineEdit *signupRepPasswordEdit;
    QSpacerItem *verticalSpacer_5;
    QPushButton *signupButton;
    QWidget *menuPage;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_11;
    QVBoxLayout *verticalLayout;
    QLabel *menuUserNameLabel;
    QLabel *menuJobTitleLabel;
    QLabel *menuTypeAccLabel;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_19;
    QPushButton *loadSendDocButton;
    QPushButton *putSignatureButton;
    QPushButton *loadSignatureButton;
    QPushButton *settingsButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *logoutButton;
    QPushButton *menuExitButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 543);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/mainIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        verticalLayout_2 = new QVBoxLayout(loginPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tabWidget = new QTabWidget(loginPage);
        tabWidget->setObjectName("tabWidget");
        QFont font1;
        font1.setPointSize(13);
        tabWidget->setFont(font1);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        loginTab = new QWidget();
        loginTab->setObjectName("loginTab");
        verticalLayout_18 = new QVBoxLayout(loginTab);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_18->addItem(verticalSpacer_8);

        label_12 = new QLabel(loginTab);
        label_12->setObjectName("label_12");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(18);
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(label_12);

        verticalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_18->addItem(verticalSpacer_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        label = new QLabel(loginTab);
        label->setObjectName("label");
        label->setFont(font1);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_15->addWidget(label);

        loginFnameEdit = new QLineEdit(loginTab);
        loginFnameEdit->setObjectName("loginFnameEdit");
        loginFnameEdit->setFont(font1);
        loginFnameEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        loginFnameEdit->setClearButtonEnabled(true);

        verticalLayout_15->addWidget(loginFnameEdit);


        verticalLayout_16->addLayout(verticalLayout_15);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_2 = new QLabel(loginTab);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_14->addWidget(label_2);

        loginLnameEdit = new QLineEdit(loginTab);
        loginLnameEdit->setObjectName("loginLnameEdit");
        loginLnameEdit->setFont(font1);
        loginLnameEdit->setInputMethodHints(Qt::ImhNone);
        loginLnameEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        loginLnameEdit->setClearButtonEnabled(true);

        verticalLayout_14->addWidget(loginLnameEdit);


        verticalLayout_16->addLayout(verticalLayout_14);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_3 = new QLabel(loginTab);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_13->addWidget(label_3);

        loginPasswordEdit = new QLineEdit(loginTab);
        loginPasswordEdit->setObjectName("loginPasswordEdit");
        loginPasswordEdit->setFont(font1);
        loginPasswordEdit->setMaxLength(30);
        loginPasswordEdit->setEchoMode(QLineEdit::Password);
        loginPasswordEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        loginPasswordEdit->setClearButtonEnabled(true);

        verticalLayout_13->addWidget(loginPasswordEdit);


        verticalLayout_16->addLayout(verticalLayout_13);

        verticalSpacer_3 = new QSpacerItem(228, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_16->addItem(verticalSpacer_3);

        loginButton = new QPushButton(loginTab);
        loginButton->setObjectName("loginButton");
        QFont font3;
        font3.setPointSize(14);
        loginButton->setFont(font3);

        verticalLayout_16->addWidget(loginButton);


        horizontalLayout_3->addLayout(verticalLayout_16);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        loginImageLabel = new QLabel(loginTab);
        loginImageLabel->setObjectName("loginImageLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loginImageLabel->sizePolicy().hasHeightForWidth());
        loginImageLabel->setSizePolicy(sizePolicy1);
        loginImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/login.png")));
        loginImageLabel->setScaledContents(false);
        loginImageLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_17->addWidget(loginImageLabel);

        verticalSpacer_7 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_17->addItem(verticalSpacer_7);

        loginExitButton = new QPushButton(loginTab);
        loginExitButton->setObjectName("loginExitButton");
        loginExitButton->setFont(font3);

        verticalLayout_17->addWidget(loginExitButton);


        horizontalLayout_3->addLayout(verticalLayout_17);


        verticalLayout_18->addLayout(horizontalLayout_3);

        tabWidget->addTab(loginTab, QString());
        signupTab = new QWidget();
        signupTab->setObjectName("signupTab");
        verticalLayout_12 = new QVBoxLayout(signupTab);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer_6);

        label_10 = new QLabel(signupTab);
        label_10->setObjectName("label_10");
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_10);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(signupTab);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_5->addWidget(label_4);

        signupFnameEdit = new QLineEdit(signupTab);
        signupFnameEdit->setObjectName("signupFnameEdit");
        signupFnameEdit->setFont(font1);
        signupFnameEdit->setCursor(QCursor(Qt::IBeamCursor));
        signupFnameEdit->setFrame(true);
        signupFnameEdit->setCursorPosition(0);
        signupFnameEdit->setClearButtonEnabled(true);

        verticalLayout_5->addWidget(signupFnameEdit);


        verticalLayout_10->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_7 = new QLabel(signupTab);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(label_7);

        signupLnameEdit = new QLineEdit(signupTab);
        signupLnameEdit->setObjectName("signupLnameEdit");
        signupLnameEdit->setFont(font1);
        signupLnameEdit->setClearButtonEnabled(true);

        verticalLayout_6->addWidget(signupLnameEdit);


        verticalLayout_10->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(signupTab);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_7->addWidget(label_5);

        signupPasswordEdit = new QLineEdit(signupTab);
        signupPasswordEdit->setObjectName("signupPasswordEdit");
        signupPasswordEdit->setFont(font1);
        signupPasswordEdit->setMaxLength(30);
        signupPasswordEdit->setEchoMode(QLineEdit::Password);
        signupPasswordEdit->setClearButtonEnabled(true);

        verticalLayout_7->addWidget(signupPasswordEdit);


        verticalLayout_10->addLayout(verticalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_10);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_9 = new QLabel(signupTab);
        label_9->setObjectName("label_9");
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        signupManageCodeLabel = new QLabel(signupTab);
        signupManageCodeLabel->setObjectName("signupManageCodeLabel");
        signupManageCodeLabel->setFont(font1);
        signupManageCodeLabel->setScaledContents(false);
        signupManageCodeLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        signupManageCodeLabel->setWordWrap(true);

        gridLayout->addWidget(signupManageCodeLabel, 0, 2, 1, 1);

        signupTypeAccComboBox = new QComboBox(signupTab);
        signupTypeAccComboBox->addItem(QString());
        signupTypeAccComboBox->addItem(QString());
        signupTypeAccComboBox->setObjectName("signupTypeAccComboBox");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(signupTypeAccComboBox->sizePolicy().hasHeightForWidth());
        signupTypeAccComboBox->setSizePolicy(sizePolicy2);
        signupTypeAccComboBox->setFont(font1);

        gridLayout->addWidget(signupTypeAccComboBox, 1, 0, 1, 1);

        signupCodeHorizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(signupCodeHorizontalSpacer, 1, 1, 1, 1);

        signupManageCodeEdit = new QLineEdit(signupTab);
        signupManageCodeEdit->setObjectName("signupManageCodeEdit");
        sizePolicy.setHeightForWidth(signupManageCodeEdit->sizePolicy().hasHeightForWidth());
        signupManageCodeEdit->setSizePolicy(sizePolicy);
        signupManageCodeEdit->setMaximumSize(QSize(100, 16777215));
        signupManageCodeEdit->setFont(font1);
        signupManageCodeEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(signupManageCodeEdit, 1, 2, 1, 1);


        verticalLayout_11->addLayout(gridLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_6 = new QLabel(signupTab);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_8->addWidget(label_6);

        signupJobTitleEdit = new QLineEdit(signupTab);
        signupJobTitleEdit->setObjectName("signupJobTitleEdit");
        signupJobTitleEdit->setEnabled(true);
        signupJobTitleEdit->setFont(font1);
        signupJobTitleEdit->setInputMethodHints(Qt::ImhPreferUppercase);
        signupJobTitleEdit->setClearButtonEnabled(true);

        verticalLayout_8->addWidget(signupJobTitleEdit);


        verticalLayout_11->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_8 = new QLabel(signupTab);
        label_8->setObjectName("label_8");
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_9->addWidget(label_8);

        signupRepPasswordEdit = new QLineEdit(signupTab);
        signupRepPasswordEdit->setObjectName("signupRepPasswordEdit");
        signupRepPasswordEdit->setFont(font1);
        signupRepPasswordEdit->setMaxLength(30);
        signupRepPasswordEdit->setEchoMode(QLineEdit::Password);
        signupRepPasswordEdit->setClearButtonEnabled(true);

        verticalLayout_9->addWidget(signupRepPasswordEdit);


        verticalLayout_11->addLayout(verticalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout_11);


        verticalLayout_12->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer_5);

        signupButton = new QPushButton(signupTab);
        signupButton->setObjectName("signupButton");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(signupButton->sizePolicy().hasHeightForWidth());
        signupButton->setSizePolicy(sizePolicy3);
        signupButton->setFont(font3);

        verticalLayout_12->addWidget(signupButton);

        tabWidget->addTab(signupTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        stackedWidget->addWidget(loginPage);
        menuPage = new QWidget();
        menuPage->setObjectName("menuPage");
        verticalLayout_3 = new QVBoxLayout(menuPage);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_10);

        label_13 = new QLabel(menuPage);
        label_13->setObjectName("label_13");
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_13);

        verticalSpacer_11 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_11);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        menuUserNameLabel = new QLabel(menuPage);
        menuUserNameLabel->setObjectName("menuUserNameLabel");
        sizePolicy2.setHeightForWidth(menuUserNameLabel->sizePolicy().hasHeightForWidth());
        menuUserNameLabel->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(16);
        menuUserNameLabel->setFont(font4);
        menuUserNameLabel->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(menuUserNameLabel);

        menuJobTitleLabel = new QLabel(menuPage);
        menuJobTitleLabel->setObjectName("menuJobTitleLabel");
        menuJobTitleLabel->setFont(font4);

        verticalLayout->addWidget(menuJobTitleLabel);

        menuTypeAccLabel = new QLabel(menuPage);
        menuTypeAccLabel->setObjectName("menuTypeAccLabel");
        menuTypeAccLabel->setFont(font4);

        verticalLayout->addWidget(menuTypeAccLabel);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(10);
        verticalLayout_19->setObjectName("verticalLayout_19");
        loadSendDocButton = new QPushButton(menuPage);
        loadSendDocButton->setObjectName("loadSendDocButton");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(loadSendDocButton->sizePolicy().hasHeightForWidth());
        loadSendDocButton->setSizePolicy(sizePolicy4);
        loadSendDocButton->setFont(font4);

        verticalLayout_19->addWidget(loadSendDocButton);

        putSignatureButton = new QPushButton(menuPage);
        putSignatureButton->setObjectName("putSignatureButton");
        sizePolicy4.setHeightForWidth(putSignatureButton->sizePolicy().hasHeightForWidth());
        putSignatureButton->setSizePolicy(sizePolicy4);
        putSignatureButton->setFont(font4);

        verticalLayout_19->addWidget(putSignatureButton);

        loadSignatureButton = new QPushButton(menuPage);
        loadSignatureButton->setObjectName("loadSignatureButton");
        sizePolicy4.setHeightForWidth(loadSignatureButton->sizePolicy().hasHeightForWidth());
        loadSignatureButton->setSizePolicy(sizePolicy4);
        loadSignatureButton->setFont(font4);

        verticalLayout_19->addWidget(loadSignatureButton);

        settingsButton = new QPushButton(menuPage);
        settingsButton->setObjectName("settingsButton");
        sizePolicy4.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy4);
        settingsButton->setFont(font4);

        verticalLayout_19->addWidget(settingsButton);


        verticalLayout_3->addLayout(verticalLayout_19);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        logoutButton = new QPushButton(menuPage);
        logoutButton->setObjectName("logoutButton");
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(logoutButton->sizePolicy().hasHeightForWidth());
        logoutButton->setSizePolicy(sizePolicy5);
        logoutButton->setFont(font3);

        horizontalLayout->addWidget(logoutButton);

        menuExitButton = new QPushButton(menuPage);
        menuExitButton->setObjectName("menuExitButton");
        sizePolicy5.setHeightForWidth(menuExitButton->sizePolicy().hasHeightForWidth());
        menuExitButton->setSizePolicy(sizePolicy5);
        menuExitButton->setFont(font3);

        horizontalLayout->addWidget(menuExitButton);


        verticalLayout_3->addLayout(horizontalLayout);

        stackedWidget->addWidget(menuPage);

        verticalLayout_4->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 700, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);
        signupTypeAccComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \321\203\320\277\321\200\320\260\320\262\320\273\321\226\320\275\320\275\321\217 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260\320\274\320\270", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\265\320\275\321\202\320\270\321\204\321\226\320\272\320\260\321\206\321\226\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \321\226\320\274'\321\217", nullptr));
        loginFnameEdit->setInputMask(QCoreApplication::translate("MainWindow", ">A<AAaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \320\277\321\200\321\226\320\267\320\262\320\270\321\211\320\265", nullptr));
        loginLnameEdit->setInputMask(QCoreApplication::translate("MainWindow", ">AAAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\265\320\275\321\202\320\270\321\204\321\226\320\272\321\203\320\262\320\260\321\202\320\270\321\201\321\217 ", nullptr));
        loginImageLabel->setText(QString());
        loginExitButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\320\270 \321\200\320\276\320\261\320\276\321\202\321\203 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(loginTab), QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\265\320\275\321\202\320\270\321\204\321\226\320\272\321\203\320\262\320\260\321\202\320\270\321\201\321\217 ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\224\321\201\321\202\321\200\320\260\321\206\321\226\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \321\226\320\274'\321\217", nullptr));
        signupFnameEdit->setInputMask(QCoreApplication::translate("MainWindow", ">A<AAaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \320\277\321\200\321\226\320\267\320\262\320\270\321\211\320\265", nullptr));
        signupLnameEdit->setInputMask(QCoreApplication::translate("MainWindow", ">AAAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\260\320\272\320\260\321\203\320\275\321\202\321\203", nullptr));
        signupManageCodeLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264 ", nullptr));
        signupTypeAccComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\321\226\320\264\320\277\320\270\321\201\320\260\320\275\321\202", nullptr));
        signupTypeAccComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\260\320\264\320\260", nullptr));
        signupJobTitleEdit->setInputMask(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\321\226\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        signupButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(signupTab), QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\217", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\273\320\276\320\262\320\275\320\265 \320\274\320\265\320\275\321\216", nullptr));
        menuUserNameLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\321\202\320\260\321\224\320\274\320\276, ", nullptr));
        menuJobTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\260\320\264\320\260: ", nullptr));
        menuTypeAccLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\260\320\272\320\260\321\203\320\275\321\202\320\260: ", nullptr));
        loadSendDocButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\320\265\320\264\320\266\320\274\320\265\320\275\321\202 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\321\226\320\262", nullptr));
        putSignatureButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\275\321\203\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\270 \321\202\320\260 \320\277\320\276\321\201\321\202\320\260\320\262\320\270\321\202\320\270 \320\277\321\226\320\264\320\277\320\270\321\201", nullptr));
        loadSignatureButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \321\201\320\262\321\226\320\271 \320\277\321\226\320\264\320\277\320\270\321\201", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\274\321\226\320\275\320\270\321\202\320\270 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\270", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270 \320\267 \320\260\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        menuExitButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\320\270 \321\200\320\276\320\261\320\276\321\202\321\203 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
