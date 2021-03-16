#include <iostream>
#include <string>
#include "Multiplier.hpp"
#include "TestSuite.hpp"

using namespace std;

void printArr(bool *arr, size_t size);

int main()
{
    /*bool arra[16] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1};
    bool arrb[16] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1};
    Multiplier *myMult = new Multiplier();
    bool *result;

    cout << "CYCLE\t\tMD\t\t\tAC\t\t\tMQ\t\t\t\t\tMQ1\n";

    result = myMult->multiply(arra, arrb);
    printArr(result, 32);

    delete result;
    result = nullptr;
    delete myMult;
    myMult = nullptr;*/

    return 0;
}

void printArr(bool *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void test()
{
    TestSuite Test;
    Multiplier Mult;
    
    const int NUM_INC = pow(2, ALU_BITS);

    bool arrPos[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool arrNeg[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    bool arrPosTurtle[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool arrNegTurtle[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    //pos 
    for (size_t i = 0; i < NUM_INC; i++)
    {
        int target;
        int val0 = Test.binaryToDecimal(arrPos, ALU_BITS);

    }
    

}