//
// Created by oriya on 1/9/19.
//

#ifndef UNTITLED9_STRING_H
#define UNTITLED9_STRING_H

#include "Stringable.h"

class MyString: public Stringable{
    string myString;
public:
    MyString(string myString);
    string &toString() override;
};
#endif //UNTITLED9_STRING_H
