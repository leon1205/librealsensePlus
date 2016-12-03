#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T08:50:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RealSenseExample
TEMPLATE = app

CONFIG+= -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
        rsdevice.cpp

HEADERS  += mainwindow.h \
    rsdevice.h

FORMS    += mainwindow.ui

unix|win32: LIBS += -lrealsense


QMAKE_CFLAGS += -std=c++11
QMAKE_CXXFLAGS = $$QMAKE_CFLAGS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lrealsense
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lrealsense
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lrealsense


INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

INCLUDEPATH += /usr/local/opencv3.1/include/opencv
INCLUDEPATH += /usr/local/opencv3.1/include/opencv2

DEPENDPATH += /usr/local/opencv3.1/include/opencv
DEPENDPATH += /usr/local/opencv3.1/include/opencv2

LIBS += -L/usr/local/opencv3.1/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc
unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
