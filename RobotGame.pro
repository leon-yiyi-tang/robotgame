TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/CommandFactory.cpp \
        src/Direction.cpp \
        src/GameApp.cpp \
        src/GameTable.cpp \
        src/ReportCommand.cpp \
        src/main.cpp \
        src/MoveCommand.cpp \
        src/PlaceCommand.cpp \
        src/Robot.cpp \
        src/RotateCommand.cpp

HEADERS += \
    src/CommandFactory.h \
    src/Position.h \
    src/CmdException.h \
    src/Command.h \
    src/Direction.h \
    src/GameApp.h \
    src/GameTable.h \
    src/MoveCommand.h \
    src/NoRobotException.h \
    src/PlaceCommand.h \
    src/ReportCommand.h \
    src/Robot.h \
    src/RotateCommand.h \
    src/StringHelper.h


