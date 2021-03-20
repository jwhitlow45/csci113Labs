#include <iostream>
#include <string>
#include "Multiplier.hpp"

using namespace std;

bool *getUserBinary(string);         //get binary from user and return binary array
void stringToBinary(string, bool *); //convert string to binary array
void printArr(bool *, size_t);       //print passed array

int main()
{
    //Strings for binary values found in the lab
    string md0 = "0000000110101001";
    string mq0 = "1111111100110101";
    string md1 = "0000000000101001";
    string mq1 = "1111111111110101";
    string md2 = "1111111111110101";
    string mq2 = "0000000000101001";

    // Multiplier object and pointer to store result pointer
    Multiplier *myMult = new Multiplier();
    bool *result;

    string sUserMD;  //user string containing md register
    string sUserMQ;  //user string containing mq register
    bool userMD[16]; //md register converted to binary array
    bool userMQ[16]; //mq register converted to binary array

    cout << "Booth's Multiplication Simulator\n"
         << "--------------------------------\n"
         << "Enter a 16-bit binary number for MD register: ";
    getline(cin, sUserMD);
    stringToBinary(sUserMD, userMD);

    cout << "Enter a 16-bit binary number for MQ register: ";
    getline(cin, sUserMQ);
    stringToBinary(sUserMQ, userMQ);

    cout << "\n   Emulating\n";
    printArr(userMD, 16);
    cout << "\t*\n";
    printArr(userMQ, 16);

    cout << "\nCYCLE\t\tMD\t\t\tAC\t\t\tMQ\t\t\t\t\tMQ1\n";
    result = myMult->multiply(userMD, userMQ);
    cout << "\nResult: ";
    printArr(result, ALU_BITS * 2);
    cout << endl;

    delete result;
    result = nullptr;
    delete myMult;
    myMult = nullptr;

    return 0;
}

void stringToBinary(string inputStr, bool *storageArr)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        storageArr[i] = inputStr[i] - '0'; //convert num char to dec
}

void printArr(bool *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}