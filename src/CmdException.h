#ifndef CMDEXCEPTION_H
#define CMDEXCEPTION_H

//#include <iostream>
#include <exception>
#include <sstream>

#include "Command.h"

using namespace std;

namespace robotgame {


class CmdException : public exception {

public:
    CmdException(const char* cmd, const char* msg)
        :m_cmd(cmd),m_msg(msg){

    }


    const char * what () const throw () {
        stringstream ss;
        ss << m_cmd << ": " << m_msg;
        return ss.str().data();
    }

    string toString() const {
        stringstream ss;
        ss << m_cmd << ": " << m_msg;
        return ss.str();
    }

private:
    string m_cmd; //TODO: is it the right way
    string m_msg;

};

}


#endif // CMDEXCEPTION_H
