#pragma once
#include "ALU.hpp"

#define CYCLE_COUNTER_BITS 4

class Multiplier
{
private:
    ALU *ALUComp;

    //registers
    bool MD[ALU_BITS]; //register MD
    bool AC[ALU_BITS]; //register AC
    bool MQ[ALU_BITS]; //register MQ

    bool cycleCounter[CYCLE_COUNTER_BITS]; //cycle counter

    //--------Cycle counter methods--------
    //setter method
    void initCycleCounter();

public:
    void decCycleCounter();
    //--------Register methods--------
    //register accessors
    bool *getMD() { return MD; };
    bool *getAC() { return AC; };
    bool *getMQ() { return MQ; };
    bool *getCycleCounter() { return cycleCounter; }

    void setMD(bool *); //set MD to passed value
    void setAC(bool *); //set AC to passed value
    void setMQ(bool *); //set MQ to passed value

    void clearMD(); //clear MD to 0's
    void clearAC(); //clear AC to 0's
    void clearMQ(); //clear MQ to 0's

    //--------Operations--------

    //constructors
    Multiplier();
    ~Multiplier();
};
