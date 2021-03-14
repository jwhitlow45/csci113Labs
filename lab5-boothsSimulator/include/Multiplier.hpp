#pragma once
#include "ALU.hpp"

#define CYCLE_COUNTER_BITS 4

class Multiplier
{
private:
    //registers
    bool MD[ALU_BITS]; //register MD
    bool AC[ALU_BITS]; //register AC
    bool MQ[ALU_BITS]; //register MQ
    bool MQ1;          //fall off bit from MQ

    bool cycleCounter[CYCLE_COUNTER_BITS]; //cycle counter

    //--------Cycle counter methods--------
    //init method
    void initCycleCounter();
    void decCycleCounter();

public:
    //ALU Component
    ALU *ALUComp;

    //--------Register methods--------
    //register accessors
    bool *getMD() { return MD; };
    bool *getAC() { return AC; };
    bool *getMQ() { return MQ; };
    bool getMQ1() { return MQ1; }
    bool *getCycleCounter() { return cycleCounter; }

    void setMD(bool *);                  //set MD to passed value
    void setAC(bool *);                  //set AC to passed value
    void setMQ(bool *);                  //set MQ to passed value
    void setMQ1(bool arg) { MQ1 = arg; } //set MQ1 to passed value

    void clearMD();                //clear MD to 0's
    void clearAC();                //clear AC to 0's
    void clearMQ();                //clear MQ to 0's
    void clearMQ1() { setMQ1(0); } //clear MQ1 to 0

    //--------Operations--------
    bool arithmeticRightShift(bool *);
    bool* multiply(bool *, bool *);
    void displayRegister(bool *);
    void display();

    //constructors
    Multiplier();
    ~Multiplier();
};
