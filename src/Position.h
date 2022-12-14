#ifndef POSITION_H
#define POSITION_H


namespace RobotGame {

    struct Position {
        int x;
        int y;
    public:
        Position(int x, int y)
                : x(x), y(y) {}
    };

}

#endif // POSITION_H
