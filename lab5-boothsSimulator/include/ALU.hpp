#define ALU_BITS 16

using namespace std;

class ALU
{
private:
    bool A[ALU_BITS];            //a register for alu
    bool B[ALU_BITS];            //b register for alu
    bool carry;                  //carry bit for alu
    bool overflow;               //overflow bit for alu

public:
    //--------Member modifications methods--------
    //A getter
    bool *getA() { return A; }

    //B getter
    bool *getB() { return B; }

    //set input to arg
    void setA(bool *);
    //clear inputs to 0000 0000 0000 0000
    void clearA();

    //set input to arg
    void setB(bool *);
    //clear inputs to 0000 0000 0000 0000
    void clearB();

    //set carry
    void setCarry() { carry = true; }
    //clear carry
    void clearCarry() { carry = false; }
    //get carry
    bool getCarry() { return carry; }

    //set overflow
    void setOverflow() { overflow = 1; }
    //clear overflow
    void clearOverflow() { overflow = 0; }
    //get overflow
    bool getOverflow() { return overflow; }

    //--------ALU Operations--------
    bool *add();
    bool *subtract();
    void negate(bool arg[ALU_BITS]);

    //constructor
    ALU();
};