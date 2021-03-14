#include "Multiplier.hpp"

using namespace std;

//--------Cycle counter methods--------
void Multiplier::initCycleCounter()
{
    bool set[CYCLE_COUNTER_BITS] = {1, 1, 1, 1};
    for (size_t i = 0; i < CYCLE_COUNTER_BITS; i++)
        cycleCounter[i] = set[i];
}

void Multiplier::decCycleCounter()
{
    for (int i = CYCLE_COUNTER_BITS; i > -1; i--)
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
void Multiplier::arithmeticRightShift(bool *value)
{
    for (size_t i = ALU_BITS - 1; i > 0; i--)
        value[i] = value[i - 1];
}

void Multiplier::multiply(bool* argMD, bool* argMQ)
{
    initCycleCounter();
    clearAC();
    setMD(argMD);
    setMQ(argMQ);
    bool MQNext = 0;

    for (size_t i = 0; i < 16; i++)
    {
        /* code */
    }
    
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