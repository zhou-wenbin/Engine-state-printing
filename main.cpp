#include <iostream>
#include <string>
using namespace std;
int rotateLeft (int value, int amount)
{
    //four bit rotate left

    const int OVER_FLOW = 0b10000;
    while (amount > 0)
    {
        value = value << 1;
        if (((value & OVER_FLOW) == OVER_FLOW))
        {
            value = value & 0b1111;  //remove overflow bit
            value = value | 0b0001;  //set the rightmost bit
        }
        amount--;
    }
    return value;
}

int stateprinting(int cylinderFire, int outValvesOpen,int pistonUp, int inValvesOpen, string d1,
                  string d2, string d3, string d4, string d5, string d6 )
{

    for (int c = 0; c < 4; c++) {
        int positionMask = 0b1000;
        positionMask = positionMask >> c;

        if (((positionMask & inValvesOpen) == inValvesOpen)) {
            d3[1 + c * 9] = 'o';
            d6[4 + c * 9] = 'I';
        }

        if ((positionMask & outValvesOpen) == outValvesOpen) {
            d3[7 + c * 9] = 'o';
            d6[4 + c * 9] = 'E';
        }

        if (((positionMask | pistonUp) == pistonUp)) {
            d3[4 + c * 9] = 'T';
        } else {
            d4[4 + c * 9] = 'T';
        }
        if ((positionMask & cylinderFire) == cylinderFire) {
            d3[3 + c * 9] = '*';
            d3[5 + c * 9] = '*';
            d6[4 + c * 9] = 'P';
        }

        if ((d4[4 + c * 9] == 'T') & (d3[7 + c * 9] == 'x')) {
            d6[4 + c * 9] = 'C';
        }
    }
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << d4 << endl;
    cout << d5 << endl;
    cout << d6 << endl;
    cout << "  " << endl;
    return 0;

}

int main() {
        int inValvesOpen = 0b0010, outValvesOpen = 0b0100, pistonUp = 0b1010, cylinderFire =0b1000;
        int bitsToRotate =0;

    string d1 = "    1        2        3        4   ";
    string d2 = "   ___      ___      ___      ___  ";
    string d3 = " x|   |x  x|   |x  x|   |x  x|   |x";
    string d4 = "  |   |    |   |    |   |    |   | ";
    string d5 = "   ___      ___      ___      ___  ";
    string d6 = "    ?        ?        ?        ?   ";

    stateprinting(cylinderFire, outValvesOpen, pistonUp, inValvesOpen, d1, d2, d3, d4, d5, d6);
    bitsToRotate = 2;
    cylinderFire = rotateLeft(cylinderFire, bitsToRotate);
    inValvesOpen = rotateLeft(inValvesOpen, bitsToRotate);
    outValvesOpen = rotateLeft(outValvesOpen, bitsToRotate);
    pistonUp = rotateLeft(pistonUp, bitsToRotate);


    stateprinting(cylinderFire, outValvesOpen, pistonUp, inValvesOpen, d1, d2, d3, d4, d5, d6);
    bitsToRotate = 1;
    cylinderFire = rotateLeft(cylinderFire, bitsToRotate);
    inValvesOpen = rotateLeft(inValvesOpen, bitsToRotate);
    outValvesOpen = rotateLeft(outValvesOpen, bitsToRotate);
    pistonUp = rotateLeft(pistonUp, bitsToRotate);

    stateprinting(cylinderFire, outValvesOpen, pistonUp, inValvesOpen, d1, d2, d3, d4, d5, d6);
    bitsToRotate = 2;
    cylinderFire = rotateLeft(cylinderFire, bitsToRotate);
    inValvesOpen = rotateLeft(inValvesOpen, bitsToRotate);
    outValvesOpen = rotateLeft(outValvesOpen, bitsToRotate);
    pistonUp = rotateLeft(pistonUp, bitsToRotate);

    stateprinting(cylinderFire, outValvesOpen, pistonUp, inValvesOpen, d1, d2, d3, d4, d5, d6);
    bitsToRotate = 3;
    cylinderFire = rotateLeft(cylinderFire, bitsToRotate);
    inValvesOpen = rotateLeft(inValvesOpen, bitsToRotate);
    outValvesOpen = rotateLeft(outValvesOpen, bitsToRotate);
    pistonUp = rotateLeft(pistonUp, bitsToRotate);

    stateprinting(cylinderFire, outValvesOpen, pistonUp, inValvesOpen, d1, d2, d3, d4, d5, d6);


}
