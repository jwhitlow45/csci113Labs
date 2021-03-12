#pragma once
#include <string>

using namespace std;

class ALU
{
private:
    bool control[4];
    string A;
    string B;

public:
    void setControl(bool arg[4]);
    void clearControl(bool arg[4]) { setControl(arg); }
    bool* getControl() { return control; }

    void add();
    void subtract();
    void execute();

    ALU()
    {
    }

    ~ALU()
    {
    }
};