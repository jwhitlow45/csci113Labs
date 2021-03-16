#include "TestSuite.hpp"

int TestSuite::binaryToDecimal(bool value[], size_t size)
{
    bool negative = value[0];
    int total = 0;

    //if value is negative perform twos comp
    if (negative)
    {
        twoPosComp(value, size);
    }
    //convert value to decimal
    for (size_t i = 1; i < size; i++)
        total += (value[i] * pow(2, size - i - 1));
    //make value negative if bin was negative
    if (negative)
        total *= -1;
    return total;
}

void TestSuite::incPosBinary(bool value[], size_t size)
{
    for (int i = 15; i > -1; i--)
    {
        if (value[i] == 0) //find first index where value is 0
        {
            value[i] = 1;  //set value at that index to 1
            while (i < 15) //set all values to the right to 0
            {
                i++;
                value[i] = 0;
            }
            return;
        }
    }
}

void TestSuite::negate(bool value[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        value[i] = !value[i]; //flip all bits
}

void TestSuite::twoPosComp(bool value[], size_t size)
{
    negate(value, size);       //flip all bits
    incPosBinary(value, size); //add 1
}

bool TestSuite::comp(bool value0[], bool value1[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (value0[i] != value1[i])
            return false;
    }
    return true;
}
