#include <iostream>
#include <string>
#include "ALU.hpp"

using namespace std;

void printArr(bool *arr);

int main()
{
    ALU *myALU = new ALU();

    bool a[16] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0};
    bool b[16] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0};

    printArr(a);
    printArr(b);
    myALU->clearA();
    //myALU->setB(b);

    //printArr(myALU->add());

    delete myALU;
    myALU = nullptr;
    return 0;
}

void printArr(bool *arr)
{
    for (size_t i = 0; i < 16; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}