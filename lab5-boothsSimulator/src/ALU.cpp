#include <cstddef>
#include "ALU.hpp"

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
    //clear carry to 0
    clearCarry();
    for (int i = 15; i > -1; i++)
    {
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
    }
    return sum;
}

void ALU::subtract()
{
    return;
}

void ALU::negate(bool arg[ALU_BITS])
{
    for (size_t i = 0; i < 15; i++)
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