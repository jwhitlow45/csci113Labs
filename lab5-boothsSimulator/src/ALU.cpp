#include <cstddef>
#include "ALU.hpp"

using namespace std;

//--------Member modifications methods--------
void ALU::setControl(bool arg[ALU_CTRL_BITS])
{
    for (size_t i = 0; i < ALU_CTRL_BITS; i++)
        control[i] = arg[i];
}

void ALU::clearControl()
{
    bool clear[ALU_CTRL_BITS] = {0, 0, 0, 0};
    setControl(clear);
}

void ALU::setA(bool *value)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        getA()[i] = value[i];
}

void ALU::clearA()
{
    bool clear[ALU_BITS] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};

    setA(clear);
}

void ALU::setB(bool *value)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        getB()[i] = value[i];
}

void ALU::clearB()
{
    bool clear[ALU_BITS] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};

    setB(clear);
}

//--------ALU Operations--------

bool *ALU::add()
{
    //init array for return
    bool *sum = new bool[16];
    for (int i = 15; i > -1; i--)
    {
        bool carryIn = getCarry();
        int total = getA()[i] + getB()[i] + getCarry();
        if (total == 0)
            sum[i] = total;
        else if (total == 1)
        {
            sum[i] = total;
            clearCarry();
        }
        else if (total == 2)
        {
            sum[i] = 0;
            setCarry();
        }
        else if (total == 3)
        {
            sum[i] = 1;
            setCarry();
        }
        //if carry in does not equal carry out
        if (i == 0 && carryIn != getCarry())
        {
            clearCarry();
            throw "**OVERFLOW**";
        }
    }
    clearCarry();
    return sum;
}

bool *ALU::subtract()
{
    //perform 1's complement and set carry to 1 (2's complement)
    negate(getB());
    setCarry();
    return add();
}

void ALU::negate(bool arg[ALU_BITS])
{
    for (size_t i = 0; i < 16; i++)
        arg[i] = !arg[i];
}

// constructor
ALU::ALU()
{
    clearControl();
    clearA();
    clearB();
    clearCarry();
}