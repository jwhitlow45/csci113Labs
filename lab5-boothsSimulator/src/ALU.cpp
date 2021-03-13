#include "include/ALU.h"

using namespace std;

//--------Member modifications methods--------
void ALU::setControl(bool arg[ALU_CTRL_BITS])
{
    for (size_t i = 0; i < ALU_CTRL_BITS; i++)
        control[i] = arg[i];
}

void ALU::clearControl()
{
    bool clear[ALU_CTRL_BITS] = {0,0,0,0};
    setControl(clear);
}

void ALU::setInput(bool input[16], bool value[16])
{
    for (size_t i = 0; i < ALU_BITS; i++)
        input[i] = value[i];
}

void ALU::clearInput(bool arg[16])
{
    bool clear[ALU_BITS] = {0,0,0,0,
                            0,0,0,0,
                            0,0,0,0,
                            0,0,0,0};

    setInput(arg, clear);
}

//--------ALU Operations--------

bool* ALU::add()
{
    for (size_t i = 15; i > -1; i++)
    {
        
    }
    
}

void ALU::subtract()
{

}

void ALU::negate(bool arg[ALU_BITS])
{
    for (size_t i = 0; i < 15; i++)
        arg[i] = !arg[i];    
}