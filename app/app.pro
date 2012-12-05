QT += core gui webkit widgets

DEFINES += QT_KEYPAD_NAVIGATION

INCLUDEPATH += ../deps/goldendict
INCLUDEPATH += $${OUT_PWD}/../deps/libgd/build

LIBS += -L$${OUT_PWD}/../deps/libgd $${OUT_PWD}/../deps/goldendict/build/dictzip.o -lgd

LIBS += \
        -lz \
        -lbz2

LIBS += -lvorbisfile \
        -lvorbis \
        -logg \
        -lhunspell-1.3 \
        -liconv

TARGET = gd
TEMPLATE = app

SOURCES += main.cpp \
    kindlemainwindow.cpp

HEADERS  += \
    kindlemainwindow.h

FORMS    += \
    kindlemainwindow.ui

target.path = /mnt/us/goldendict
INSTALLS += target
