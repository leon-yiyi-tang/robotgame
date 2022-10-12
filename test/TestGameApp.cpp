

#include <gtest/gtest.h>
#include "../src/GameApp.h"
#include "../src/GameTable.h"
#include "../src/CommandFactory.h"
#include "../src/PlaceCommand.h"
#include "../src/Direction.h"
#include "../src/CmdException.h"
#include "../src/MoveCommand.h"
#include "../src/RotateCommand.h"

using namespace std;

namespace RobotGame {

    class TestGameApp : public ::testing::Test {


    public:
        void testParsePlaceCommand(const string &cmdStr, int x, int y, DIRECTION direction) {
            CommandPtr cmd = CommandFactory::parseCommand(cmdStr);
            EXPECT_TRUE(cmd);
            EXPECT_EQ(cmd->getType(), Command::CMD_PLACE);
            PlaceCommand *pCmd = dynamic_cast<PlaceCommand *>(cmd.get());
            EXPECT_TRUE(pCmd != NULL);

            EXPECT_TRUE(pCmd->getX() == x
                        && pCmd->getY() == y
                        && pCmd->getDirection() == direction);
        }

        void testParseInvalidPlaceCommand(const string &cmdStr) {

            EXPECT_THROW(CommandFactory::parseCommand(cmdStr), exception);
        }

        void testParseSimpleCommand(const string &cmdStr, Command::CmdType type) {
            CommandPtr cmd = CommandFactory::parseCommand(cmdStr);
            EXPECT_TRUE(cmd);
            EXPECT_EQ(cmd->getType(), type);
        }

        void testProcessPlaceCommand(int x, int y, DIRECTION direction,
                                     bool expectException) {

            GameApp app;
            EXPECT_FALSE(app.hasRobotPlaced());
            const PlaceCommand &cmd = PlaceCommand(x, y, direction);
            if (expectException) {
                EXPECT_THROW(app.processCommand(cmd), CmdException);
            } else {
                app.processCommand(cmd);
                const GameTablePtr &pTable = app.getGameTable();
                const RobotPtr &pRobot = pTable->getRobot();
                EXPECT_TRUE(pRobot->getX() == x
                            && pRobot->getY() == y
                            && pRobot->getFacingDirection() == direction);
            }
        }

        void testProcessMoveCommand(int origX, int origY, DIRECTION direction, bool expectException,
                                    int expectX, int expectY) {
            GameApp app;
            EXPECT_FALSE(app.hasRobotPlaced());
            const PlaceCommand &cmd = PlaceCommand(origX, origY, direction);
            app.processCommand(cmd);

            const GameTablePtr &pTable = app.getGameTable();
            const RobotPtr &pRobot = pTable->getRobot();

            const MoveCommand &cmd2 = MoveCommand();
            if (expectException) {
                EXPECT_THROW(app.processCommand(cmd2), CmdException);
            } else {
                app.processCommand(cmd2);
            }
            EXPECT_TRUE(pRobot->getX() == expectX
                        && pRobot->getY() == expectY
                        && pRobot->getFacingDirection() == direction);
        }

        void testProcessRotateCommand(DIRECTION direction, bool clockWise, DIRECTION expectDirection) {
            GameApp app;
            EXPECT_FALSE(app.hasRobotPlaced());
            const PlaceCommand &cmd = PlaceCommand(1, 1, direction);
            app.processCommand(cmd);

            const RotateCommand &cmd2 = RotateCommand(clockWise);

            app.processCommand(cmd2);
            const GameTablePtr &pTable = app.getGameTable();
            const RobotPtr &pRobot = pTable->getRobot();

            EXPECT_TRUE(pRobot->getFacingDirection() == expectDirection);

        }



        // Test interface
    protected:
        void SetUp() {
        }

        void TearDown() {
        }

    private:
        void TestBody() {

        }
    };

    TEST(TestCommandFactory, parsePlaceCommand) {
        TestGameApp test;
        test.testParsePlaceCommand("PLACE 4,3,NORTH", 4, 3, DIRECTION_NORTH);
        test.testParsePlaceCommand("PLACE  0, 1 ,WEST ", 0, 1, DIRECTION_WEST);
        test.testParsePlaceCommand("PLACE  0, 1 ,EAST ", 0, 1, DIRECTION_EAST);
        test.testParsePlaceCommand("PLACE  0, 1 , SOUTH ", 0, 1, DIRECTION_SOUTH);
    }

    TEST(TestCommandFactory, parseInvalidPlaceCommand) {
        TestGameApp test;
        test.testParseInvalidPlaceCommand("PLACE xxx,3,NORTH");
        test.testParseInvalidPlaceCommand("PLACE 4,xxx,NORTH");
        test.testParseInvalidPlaceCommand("PLACE 4,xxx,NORTH");
        test.testParseInvalidPlaceCommand("PLACE xxx");
    }

    TEST(TestCommandFactory, parseOtherCommands) {
        TestGameApp test;
        test.testParseSimpleCommand(" MOVE  ", Command::CMD_MOVE);
        test.testParseSimpleCommand(" LEFT  ", Command::CMD_LEFT);
        test.testParseSimpleCommand(" RIGHT  ", Command::CMD_RIGHT);
        test.testParseSimpleCommand("REPORT", Command::CMD_REPORT);
    }


    TEST(TestGameApp, processPlaceCommand) {
        TestGameApp test;
        test.testProcessPlaceCommand(1, 2, DIRECTION_EAST, false);
        test.testProcessPlaceCommand(1, 6, DIRECTION_EAST, true);
        test.testProcessPlaceCommand(1, 2, DIRECTION_UNKNOWN, true);

    }

    TEST(TestGameApp, processMoveCommand) {
        TestGameApp test;
        test.testProcessMoveCommand(1, 2, DIRECTION_EAST, false, 2, 2);
        test.testProcessMoveCommand(1, 2, DIRECTION_WEST, false, 0, 2);
        test.testProcessMoveCommand(1, 2, DIRECTION_SOUTH, false, 1, 1);
        test.testProcessMoveCommand(1, 2, DIRECTION_NORTH, false, 1, 3);

        test.testProcessMoveCommand(3, 5, DIRECTION_NORTH, true, 3, 5);
        test.testProcessMoveCommand(1, 5, DIRECTION_NORTH, true, 1, 5);
        test.testProcessMoveCommand(1, 0, DIRECTION_SOUTH, true, 1, 0);
        test.testProcessMoveCommand(4, 0, DIRECTION_SOUTH, true, 4, 0);

        test.testProcessMoveCommand(5, 1, DIRECTION_EAST, true, 5, 1);
        test.testProcessMoveCommand(5, 3, DIRECTION_EAST, true, 5, 3);

        test.testProcessMoveCommand(0, 1, DIRECTION_WEST, true, 0, 1);
        test.testProcessMoveCommand(0, 3, DIRECTION_WEST, true, 0, 3);
    }

    TEST(TestGameApp, processRotateCommand) {
        TestGameApp test;
        test.testProcessRotateCommand(DIRECTION_EAST, true, DIRECTION_SOUTH);
        test.testProcessRotateCommand(DIRECTION_SOUTH, true, DIRECTION_WEST);
        test.testProcessRotateCommand(DIRECTION_WEST, true, DIRECTION_NORTH);
        test.testProcessRotateCommand(DIRECTION_NORTH, true, DIRECTION_EAST);

        test.testProcessRotateCommand(DIRECTION_EAST, false, DIRECTION_NORTH);
        test.testProcessRotateCommand(DIRECTION_NORTH, false, DIRECTION_WEST);
        test.testProcessRotateCommand(DIRECTION_WEST, false, DIRECTION_SOUTH);
        test.testProcessRotateCommand(DIRECTION_SOUTH, false, DIRECTION_EAST);
    }


}



//int main(int argc, char** argv){
//
//    testing::InitGoogleTest(&argc, argv);
//
//    return RUN_ALL_TESTS();
//}



