#ifndef STRINGHELPER_H
#define STRINGHELPER_H


#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

namespace RobotGame {

namespace helper {

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
    return rtrim(ltrim(s));
}

void split(const string& text, vector<string>& result, char c) {
    stringstream ss(text);
    string word;
    while (getline(ss, word, c)) {
        result.push_back(word);
    }
}

}

}


#endif // STRINGHELPER_H
