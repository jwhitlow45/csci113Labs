#include <iostream>
#include <string>
#include "ALU.hpp"

using namespace std;

void printArr(bool *arr);

int main()
{
    ALU *myALU = new ALU();

    bool a[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1};
    bool b[16] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    printArr(a);
    printArr(b);
    myALU->setA(a);
    myALU->setB(b);
    cout << "--------------------\n";
    try
    {
        printArr(myALU->subtract());
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    delete myALU;
    myALU = nullptr;
    return 0;
}

void printArr(bool *arr)
{
    for (size_t i = 0; i < 16; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}