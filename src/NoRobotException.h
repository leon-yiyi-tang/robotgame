#ifndef NOROBOTEXCEPTION_H
#define NOROBOTEXCEPTION_H

#include <exception>

using namespace std;

class NoRobotException : public exception {

public:
    const char * what () const throw () {
        return "Robot is not placed yet.";
    }

};


#endif // NOROBOTEXCEPTION_H
