//
// Created by oriya on 1/9/19.
//

#include "MyString.h"

string& MyString::toString() {
    return this->myString;
}

MyString::MyString(string myString) {
    this->myString = myString;
}
