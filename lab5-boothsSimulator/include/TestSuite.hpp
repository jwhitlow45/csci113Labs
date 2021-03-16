#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class TestSuite
{
public:
    int binaryToDecimal(bool[], size_t);  //convert bin array to dec
    void incPosBinary(bool[], size_t);    //inc pos bin by 1
    void negate(bool[], size_t);          //neg bin array
    void twoPosComp(bool[], size_t);      //perform twos comp on pos bin
    bool compare(bool[], bool[], size_t); //compare two bin arrays
};