//
// Created by oriya on 1/8/19.
//

#ifndef UNTITLED9_TOSTRING_H
#define UNTITLED9_TOSTRING_H

#include "string"

using namespace std;

class Stringable {
public:
    virtual string& toString()=0;
};

#endif //UNTITLED9_TOSTRING_H
