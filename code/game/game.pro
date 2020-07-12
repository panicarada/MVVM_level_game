QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app/app.cpp \
    command/commands.cpp \
    command/game_status_command.cpp \
    command/move_command.cpp \
    main.cpp \
    model/Geometry.cpp \
    model/Map.cpp \
    model/Model.cpp \
    model/Person.cpp \
    parameter/parameters.cpp \
    view/person_ui.cpp \
    view/view.cpp \
    view_model/ViewModel.cpp

HEADERS += \
    app/app.h \
    command/FIRE_jump_move_command.h \
    command/FIRE_left_move_command.h \
    command/FIRE_right_move_command.h \
    command/ICE_jump_move_command.h \
    command/ICE_left_move_command.h \
    command/ICE_right_move_command.h \
    command/commands.h \
    command/game_status_command.h \
    command/move_command.h \
    common/Common.h \
    model/Geometry.h \
    model/Map.h \
    model/Model.h \
    model/Person.h \
    parameter/parameters.h \
    view/person_ui.h \
    view/view.h \
    view_model/ViewModel.h

FORMS += \
    view/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
