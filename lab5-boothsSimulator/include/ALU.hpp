#define ALU_BITS 16
#define ALU_CTRL_BITS 4

using namespace std;

class ALU
{
private:
    bool control[ALU_CTRL_BITS];
    bool A[ALU_BITS];
    bool B[ALU_BITS];
    bool carry;

public:
    //--------Member modifications methods--------
    // CONTROL
    //set control to passed value
    void setControl(bool arg[4]);
    //clear control to 0000
    void clearControl();
    //return control
    bool *getControl() { return control; }

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

    //--------ALU Operations--------
    bool *add();
    void subtract();
    void negate(bool arg[ALU_BITS]);

    //constructor
    ALU();
};