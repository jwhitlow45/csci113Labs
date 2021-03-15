#include <iostream>
#include "Multiplier.hpp"

using namespace std;

//--------Cycle counter methods--------
void Multiplier::initCycleCounter()
{
    for (size_t i = 0; i < CYCLE_COUNTER_BITS; i++)
        cycleCounter[i] = 1;
}

void Multiplier::decCycleCounter()
{
    for (int i = CYCLE_COUNTER_BITS - 1; i > -1; i--)
    {
        if (cycleCounter[i] == 1) //if current bit is 1
        {
            cycleCounter[i] = 0;           //set current bit to 0
            while (i < CYCLE_COUNTER_BITS) //set all preceding (right)
            {                              //bits to 1 and exit
                i++;
                cycleCounter[i] = 1;
            }
            return;
        }
    }
}

//register accessors
void Multiplier::setMD(bool *value)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        MD[i] = value[i];
};
void Multiplier::setAC(bool *value)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        AC[i] = value[i];
};
void Multiplier::setMQ(bool *value)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        MQ[i] = value[i];
};

void Multiplier::clearMD()
{
    bool clear[ALU_BITS] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
    setMD(clear);
}
void Multiplier::clearAC()
{
    bool clear[ALU_BITS] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
    setAC(clear);
}
void Multiplier::clearMQ()
{
    bool clear[ALU_BITS] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
    setMQ(clear);
}

//--------Operations--------
bool Multiplier::arithmeticRightShift(bool *value)
{
    bool falloffBit = value[ALU_BITS - 1];
    for (size_t i = ALU_BITS - 1; i > 0; i--)
        value[i] = value[i - 1];
    return falloffBit;
}

bool *Multiplier::multiply(bool *argMD, bool *argMQ)
{
    initCycleCounter(); //set cycle counter to 1111
    clearAC();          //clear ac to 0's
    setMD(argMD);       //set md to first argument
    setMQ(argMQ);       //set mq to second argument
    clearMQ1();         //clear MQ

    for (size_t i = 0; i < ALU_BITS; i++)
    { //case of 00 and 11 can be ignored as they
        //result in no change
        if (getMQ()[ALU_BITS - 1] == 0 && getMQ1() == 1)
        {
            ALUComp->setA(getAC());
            ALUComp->setB(getMD());
            ALUComp->setOp(ADD_OPCODE);
            setAC(ALUComp->execute());
        }
        else if (getMQ()[ALU_BITS - 1] == 1 && getMQ1() == 0)
        {
            ALUComp->setA(getAC());
            ALUComp->setB(getMD());
            ALUComp->setOp(SUB_OPCODE);
            setAC(ALUComp->execute());
        }

        display(); //display machine state

        //shift ac, mq and mq1 right as if they were one large register
        setMQ1(arithmeticRightShift(getMQ()));
        getMQ()[0] = arithmeticRightShift(getAC());
        cout << "shift\n";

        display();         //display machine state
        decCycleCounter(); //decrement cycle count
    }

    //copy product to result array and return result
    bool *result = new bool[32];
    for (size_t i = 0; i < ALU_BITS; i++)
    {
        result[i] = getAC()[i];
        result[i + 16] = getMQ()[i];
    }
    return result;
}

void Multiplier::displayRegister(bool *reg)
{
    for (size_t i = 0; i < ALU_BITS; i++)
        cout << reg[i];
}

void Multiplier::display()
{
    for (size_t i = 0; i < CYCLE_COUNTER_BITS; i++) //print cycle counter
        cout << getCycleCounter()[i];
    cout << '\t';
    displayRegister(getMD()); //print md register
    cout << '\t';
    displayRegister(getAC()); //print ac register
    cout << '\t';
    displayRegister(getMQ()); //print mq register

    cout << '\t' << getMQ1() << endl; //print mq1
}

//constructors
Multiplier::Multiplier()
{
    clearMD();
    clearAC();
    clearMQ();
    initCycleCounter();
    ALUComp = new ALU();
}

Multiplier::~Multiplier()
{
    delete ALUComp;
    ALUComp = nullptr;
}