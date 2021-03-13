#include <cstddef>
#include "ALU.hpp"

using namespace std;

//--------Member modifications methods--------
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
        bool carryIn = getCarry();  //capture carry in for overflow detection
        int total = getA()[i] + getB()[i] + getCarry(); //sum bits from a, b, and carry
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
            setOverflow();  //set overflow bit to show overflow occurred
        }
    }
    clearCarry();
    clearOverflow();
    return sum;
}

bool *ALU::subtract()
{
    //perform 1's complement and set carry to 1 (2's complement)
    negate(getB());
    setCarry();
    //add 2's complement of b to a to perform subtraction
    return add();
}

void ALU::negate(bool arg[ALU_BITS])
{   //perform 1's complement on register
    for (size_t i = 0; i < 16; i++)
        arg[i] = !arg[i];
}

// constructor
ALU::ALU()
{
    clearA();       //clear a to 0
    clearB();       //clear b to 0
    clearCarry();   //clear carry to 0
    clearOverflow();//clear overflow to 0
}