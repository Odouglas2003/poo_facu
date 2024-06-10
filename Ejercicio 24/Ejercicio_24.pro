QT += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = YourApplicationName
TEMPLATE = app

# Agrega tus archivos de formulario (.ui) aquí si los tienes
# FORMS += \
#    formulario1.ui \
#    formulario2.ui

SOURCES += \
    main.cpp \
    parser.cpp

HEADERS += \
    parser.h
