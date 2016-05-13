TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Parser.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Block.hpp \
    Common.hpp \
    Parser.hpp \
    Quality.hpp


INCLUDEPATH += ./TinyTestFramework/
INCLUDEPATH -= ./TinyTestFramework/main.cpp
