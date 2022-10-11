# Read Me

## Build executable 'RobotGame' and run unit tests
### Prepare
1. This project use CMake as building system. Please make sure CMake (3.14+) is installed and in the PATH environment.
2. Building tools (visual c++ for windows or g++ for linux ) are installed.
3. Make sure internet connection is working as **Google Test**  framework will be downloaded during unit tests code building  
### Build
For linux, open a terminal and go to the project directory and run the build_and_test.sh script
```shell
./build_and_test.sh
```
For Windows, open a PowerShell terminal and go to the project directory and run the build_and_test.bat script
```shell
.\build_and_test.bat
```
If the process above is successful,  the unittest messages are like this:
```shell
Test project D:/Projects/C/RobotGame/build-windows
    Start 1: TestCommandFactory.parsePlaceCommand
1/5 Test #1: TestCommandFactory.parsePlaceCommand ....   Passed    0.01 sec
    Start 2: TestCommandFactory.parseOtherCommands
2/5 Test #2: TestCommandFactory.parseOtherCommands ...   Passed    0.01 sec
    Start 3: TestGameApp.processPlaceCommand
3/5 Test #3: TestGameApp.processPlaceCommand .........   Passed    0.01 sec
    Start 4: TestGameApp.processMoveCommand
4/5 Test #4: TestGameApp.processMoveCommand ..........   Passed    0.01 sec
    Start 5: TestGameApp.processRotateCommand
5/5 Test #5: TestGameApp.processRotateCommand ........   Passed    0.01 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.06 sec
```

## Run the main program 'RobotGame'
For linux, 
~~~shell
./build-linux/RobotGame
~~~
For Windows,
~~~shell
.\build-windows\Debug\RobotGame.exe
~~~
