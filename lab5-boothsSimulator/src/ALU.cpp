#include "include/ALU.h"

using namespace std;

void ALU::setControl(bool arg[4])
{
    for (size_t i = 0; i < 3; i++)
        control[i] = arg[i];
}

void ALU::add()
{
    bool carry = false;
}