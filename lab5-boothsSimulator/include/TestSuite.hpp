#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class TestSuite
{
public:
    int binaryToDecimal(bool[], size_t);
    void incPosBinary(bool[], size_t);
    void negate(bool[], size_t);
    void twoPosComp(bool[], size_t);
    bool comp (bool[], bool[], size_t);
};