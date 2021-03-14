#include <iostream>
#include <string>
#include "Multiplier.hpp"

using namespace std;

void printArr(bool *arr, size_t size);

int main()
{
    Multiplier *myMult = new Multiplier();

    for (size_t i = 0; i < 15; i++)
    {
        myMult->decCycleCounter();
        printArr(myMult->getCycleCounter(), 4);
    }

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