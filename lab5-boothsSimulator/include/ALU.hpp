#pragma once
#include <cstddef>
#include <string>
#define ALU_BITS 16
#define OP_BITS 2
#define ADD_OPCODE "10"
#define SUB_OPCODE "01"

using namespace std;

class ALU
{
private:
    bool A[ALU_BITS]; //a register for alu
    bool B[ALU_BITS]; //b register for alu
    string op;        //op register for alu
    bool carry;       //carry bit for alu
    bool overflow;    //overflow bit for alu

public:
    //--------Register methods--------
    //register accessors
    bool *getA() { return A; }
    bool *getB() { return B; }
    string getOp() { return op; }
    bool getCarry() { return carry; }
    bool getOverflow() { return overflow; }

    void setA(bool *);                   //set a to passed value
    void setB(bool *);                   //set b to passed value
    void setOp(string arg) { op = arg; } //set op to passed value
    void setCarry() { carry = 1; }       //set carry to 1
    void setOverflow() { overflow = 1; } //set overflow to 1

    void clearA();                         //clear a to 0's
    void clearB();                         //clear b to 0's
    void clearOp() { setOp("00"); };       //clear op to 0's
    void clearCarry() { carry = 0; }       //clear carry to 0
    void clearOverflow() { overflow = 0; } //clear overflow to 0

    //--------ALU Operations--------
    bool *add();                     //add values in a and b (a+b)
    bool *subtract();                //sub values in a and b (a-b)
    void negate(bool arg[ALU_BITS]); //flip all bits in passed value
    void execute();                  //execute alu on current values
                                     //in its registers
    //constructor
    ALU();
};