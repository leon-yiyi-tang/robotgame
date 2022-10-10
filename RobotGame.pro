TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CommandFactory.cpp \
        Direction.cpp \
        GameApp.cpp \
        GameTable.cpp \
        ReportCommand.cpp \
        main.cpp \
        MoveCommand.cpp \
        PlaceCommand.cpp \
        Robot.cpp \
        RotateCommand.cpp

HEADERS += \
    CommandFactory.h \
    Position.h \
    CmdException.h \
    Command.h \
    Direction.h \
    GameApp.h \
    GameTable.h \
    MoveCommand.h \
    NoRobotException.h \
    PlaceCommand.h \
    ReportCommand.h \
    Robot.h \
    RotateCommand.h \
    StringHelper.h
