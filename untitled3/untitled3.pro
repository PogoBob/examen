QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_exam_test.cpp \
    ../exam/func_for_server.cpp \
    ../exam/mytcpserver.cpp

SUBDIRS += \
    ../exam/exam.pro

HEADERS += \
    ../exam/func_for_server.h \
    ../exam/mytcpserver.h
