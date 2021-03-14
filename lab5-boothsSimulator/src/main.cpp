#include <iostream>
#include <string>
#include "Multiplier.hpp"

using namespace std;

void printArr(bool *arr, size_t size);

int main()
{
    Multiplier *myMult = new Multiplier();

    bool arrb[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
    bool arra[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
    bool *result;

    cout << "cycle\tmd\t\t\t\tac\t\t\t\tmq\t\t\t\tmq1\n";

    result = myMult->multiply(arra, arrb);
    printArr(result, 32);

    delete result;
    result = nullptr;
    delete myMult;
    myMult = nullptr;

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