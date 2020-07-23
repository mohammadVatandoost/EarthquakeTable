QT += quick
QT += serialport
QT += sql
QT += qml
QT += charts
QT += opengl
QT += quickcontrols2
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Biquad.cpp \
    Butterworth.cpp \
    Cascade.cpp \
    PoleFilter.cpp \
    State.cpp \
    assistant.cpp \
    fileitemslist.cpp \
    fileitemsmodel.cpp \
        main.cpp \
    backend.cpp \
    csv.cpp \
    sensorslist.cpp \
    jsonstoring.cpp \
    groundmotionlist.cpp \
    groundmotionmodel.cpp \
    colibrateitemlist.cpp \
    colibrateitemmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Biquad.h \
    Butterworth.h \
    Cascade.h \
    Common.h \
    FileItem.h \
    Layout.h \
    MathSupplement.h \
    PoleFilter.h \
    State.h \
    Types.h \
    assistant.h \
    assistant.h \
    backend.h \
    fileitemslist.h \
    fileitemsmodel.h \
    sensor.h \
    packet.h \
    csv.h \
    myutitlity.h \
    sensorslist.h \
    jsonstoring.h \
    generaldata.h \
    groundmotionlist.h \
    groundmotionmodel.h \
    colibrateitemlist.h \
    colibrateitemmodel.h

DISTFILES += \
    MaterialDesignIcon.qml \

#unix:!macx: LIBS += -L$$PWD/../../../../../../../../usr/local/lib/ -liir_static

#INCLUDEPATH += $$PWD/../../../../../../../../usr/local/include
#DEPENDPATH += $$PWD/../../../../../../../../usr/local/include

#unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../../../../usr/local/lib/libiir_static.a
