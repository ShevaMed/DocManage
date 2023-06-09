QT       += core gui sql axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    docoperations.cpp \
    loaddocform.cpp \
    loadsenddocform.cpp \
    loadsignatureform.cpp \
    main.cpp \
    mainwindow.cpp \
    messagehandler.cpp \
    putsignatureform.cpp \
    settingsform.cpp

HEADERS += \
    dbmanager.h \
    docoperations.h \
    loaddocform.h \
    loadsenddocform.h \
    loadsignatureform.h \
    mainwindow.h \
    messagehandler.h \
    putsignatureform.h \
    settingsform.h

FORMS += \
    forms/loaddocform.ui \
    forms/loadsenddocform.ui \
    forms/loadsignatureform.ui \
    forms/mainwindow.ui \
    forms/putsignatureform.ui \
    forms/settingsform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
