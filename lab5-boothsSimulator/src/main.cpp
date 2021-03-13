#include <iostream>
#include <string>
#include "ALU.hpp"

using namespace std;

void printArr(bool *arr);

int main()
{
    /*ALU throws const char* exception on overflow*/
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