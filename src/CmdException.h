#ifndef CMDEXCEPTION_H
#define CMDEXCEPTION_H

//#include <iostream>
#include <exception>
#include <sstream>

#include "Command.h"

using namespace std;

namespace RobotGame {


class CmdException : public exception {

public:
    CmdException(const char* cmd, const char* msg)
        : cmd(cmd), msg(msg){

    }

    const char * what () const throw () {
        stringstream ss;
        ss << cmd << ": " << msg;
        return ss.str().data();
    }

    string toString() const {
        stringstream ss;
        ss << cmd << ": " << msg;
        return ss.str();
    }

private:
    string cmd;
    string msg;
};

}


#endif // CMDEXCEPTION_H
