TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    component.cpp \
    device.cpp \
    light.cpp \
    room.cpp \
    factory.cpp \
    roomfactory.cpp \
    appliance.cpp \
    state.cpp \
    on.cpp \
    off.cpp \
    appliancefactory.cpp \
    devicefactory.cpp \
    lightfactory.cpp \
    observer.cpp

HEADERS += \
    component.h \
    device.h \
    light.h \
    room.h \
    factory.h \
    roomfactory.h \
    appliance.h \
    state.h \
    on.h \
    off.h \
    appliancefactory.h \
    devicefactory.h \
    lightfactory.h \
    observer.h

