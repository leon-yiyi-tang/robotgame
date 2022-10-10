cmake_minimum_required(VERSION 3.10)

# set the project name
project(RobotGame)

SET(SRC_LIST src/CommandFactory.cpp 
        src/Direction.cpp 
        src/GameApp.cpp 
        src/GameTable.cpp 
        src/ReportCommand.cpp 
        src/main.cpp 
        src/MoveCommand.cpp 
        src/PlaceCommand.cpp 
        src/Robot.cpp 
        src/RotateCommand.cpp
    )

# add the executable
add_executable(RobotGame SRC_LIST)