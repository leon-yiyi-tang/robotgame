#ifndef POSITION_H
#define POSITION_H


namespace robotgame {


struct Position {
    int x;
    int y;
public:
    Position(int x, int y)
        :x(x),y(y){}
};

}

#endif // POSITION_H
