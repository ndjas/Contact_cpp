QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    src/models/Contact.cpp \
    src/models/ContactManager.cpp \
    src/storage/JSONStorage.cpp \
    src/storage/PostgresStorage.cpp \
    src/views/MainWindow.cpp \
    src/views/ContactDialog.cpp \
    src/views/PostgresConfigDialog.cpp \
    src/utils/Validator.cpp

HEADERS += \
    src/models/Contact.h \
    src/models/ContactManager.h \
    src/storage/IStorage.h \
    src/storage/JSONStorage.h \
    src/storage/PostgresStorage.h \
    src/views/MainWindow.h \
    src/views/ContactDialog.h \
    src/views/PostgresConfigDialog.h \
    src/utils/Validator.h

FORMS += \
    src/views/MainWindow.ui \
    src/views/ContactDialog.ui \
    src/views/PostgresConfigDialog.ui

INCLUDEPATH += $$PWD/lib

DESTDIR = $$PWD/build
OBJECTS_DIR = $$PWD/build/obj
MOC_DIR = $$PWD/build/moc
UI_DIR = $$PWD/build/ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
