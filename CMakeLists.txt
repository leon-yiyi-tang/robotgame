cmake_minimum_required(VERSION 3.14)

# set the project name
project(RobotGame)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

SET(SRC_LIST 
        src/CommandFactory.cpp 
        src/Direction.cpp 
        src/GameApp.cpp 
        src/GameTable.cpp 
        src/ReportCommand.cpp 
        src/MoveCommand.cpp 
        src/PlaceCommand.cpp 
        src/Robot.cpp 
        src/RotateCommand.cpp
    )

# add the executable
add_executable(RobotGame ${SRC_LIST} src/main.cpp )

enable_testing()
# add the executable
add_executable(TestGameApp ${SRC_LIST} test/TestGameApp.cpp )

target_link_libraries(
  TestGameApp # test executable
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestGameApp)


