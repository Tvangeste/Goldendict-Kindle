TEMPLATE = lib
CONFIG += sharedlib

VERSION = 1.0.0

QT += webkit
QT += xml
QT += network
QT += phonon

CONFIG += exceptions \
    rtti \
    stl

TARGET = gd

OBJECTS_DIR = build
UI_DIR = build
MOC_DIR = build
RCC_DIR = build

DEFINES += QT_KEYPAD_NAVIGATION
DEFINES += LIBGD_LIBRARY
DEFINES += PROGRAM_VERSION=\\\"$$VERSION\\\"

INCLUDEPATH += ../goldendict

SOURCES  = $$files(../goldendict/*.cc)
SOURCES += libgd.cpp

# remove windows-specific files
SOURCES ~= s/\\S+(wordbyauto|x64).cc//g

HEADERS = $$files(../goldendict/*.hh)
HEADERS += libgd.h\
        libgd_global.h

FORMS = $$files(../goldendict/*.ui)

# symlinks do not work on Kindle, install the real file
QMAKE_POST_LINK += rm -f $$OUT_PWD/libgd.so.1; cp -f $$OUT_PWD/libgd.so.1.0.0 $$OUT_PWD/libgd.so.1
libgd.files = $$OUT_PWD/libgd.so.1
libgd.path = /mnt/us/goldendict/lib
INSTALLS += libgd

include( ../goldendict/qtsingleapplication/src/qtsingleapplication.pri )
