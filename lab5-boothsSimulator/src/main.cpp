#include <iostream>
#include <string>
#include "ALU.hpp"

using namespace std;

void printArr(bool *arr);

int main()
{
    
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