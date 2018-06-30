#include <iostream>

using namespace std;

int checkLSB(unsigned long x) {
    // 1 in binary is 0001, so AND the last bit
    int lsb = x & 1;

    return lsb;
}

int checkMSB(unsigned long x) {
    int bits = sizeof (unsigned long) * 8;
    int msb = 1 << (bits - 1);
    msb = msb & x;

    return msb;
}

int checknthBit(unsigned long x, int n) {
    int bit = (x >> n) & 1;

    return bit;
}

int setnthBit(unsigned long x, int n) {
    int setBit = (1 << n) | x;

    return setBit;
}

int toggleNth(unsigned long x, int n) {
    int toggleBit = (1 << n) ^ x;

    return toggleBit;
}

// -1 = 1111 1111 1111 ... etc in binary
int highestOrder(unsigned long x) {
    int cnt = sizeof (unsigned long) * 8;
    int order = -1;
    for (int i = 0; i < cnt; i++) {
        if ((x >> i) & 1) {
            order = i;
        }
    }

    if (order != -1) {
        // has a highest order set bit
    } else {
        // no set bits
    }

    return order;
}

int lowestOrder(unsigned long x) {
    int low = 0;
    int cnt = 0;
    while (x) {
        if (x & 1) {
            low = cnt;
            return low;
        }
        x = x >> 1;
        cnt++;
    }
    return -1;
}

int countTrailingZero(unsigned long x) {
    int cnt = 0;
    while (x) {
        if (!(x & 1)) {
            cnt++;
        } else {
            break;
        }
        x = x >> 1;
    }
    return cnt;
}

int clearNth(unsigned long x, int n) {
    int clr = 1 << n;
    x = x & (~clr);
    return x;
}

int countLeadingZero(unsigned long x) {
    int numBits = sizeof(unsigned long) * 8;
    int msb = 1 << (numBits - 1);
    int cnt = 0;

    while (!(x & msb)) {
        cnt++;
        msb = msb >> 1;
    }

    return cnt;
}

int flipBits(unsigned long x) {
    int val = ~x;
    return val;
}

void numZeroOnes(unsigned long x) {
    int numBits = sizeof(unsigned long) * 8;
    int z = 0;
    int o = 0;
    for (int i = 0; i < numBits; i++) {
        if (x & (1 << i)) {
            o++;
        } else {
            z++;
        }
    }
    cout << "Zeros: " << z << "\tOnes: " << o << "\t\tNumber: " << x << endl;
}

int rotateRight(unsigned long x) {
    int DROPPED_LSB;
    int rot = 2;
    int bitSize = sizeof(unsigned long) * 8;
    while (rot--) {
        DROPPED_LSB = x & 1;        // grab before dropped

        // shift num by 1 and clear MSB
        x = (x >> 1) & (~(1 << bitSize - 1));
        x = x | (DROPPED_LSB << bitSize - 1);

    }

    return x;
}

int rotateLeft(unsigned long x) {
    int DROPPED_MSB;
    int rot = 2;
    int bitSize = sizeof(unsigned long) * 8;
    while (rot--) {
        DROPPED_MSB = (x >> bitSize - 1) & 1;

        x = (x << 1) | DROPPED_MSB;
    }
    return x;
}

void decimalToBinary(unsigned long x) {
    int bitSize = sizeof(unsigned long) * 8;
    int LSB;
    for (int i = bitSize - 1; i >= 0; i--) {
        LSB = (x >> i) & 1;
        cout << LSB;
    }
}

void swapNumbers(unsigned long x, unsigned long y) {
    int bitSize = sizeof(unsigned long) * 8;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "\tAfter\n";
    for (int i = 0; i < bitSize; i++) {
        // find bit of a and b and see if they match, if not, change the bit
        if (((x >> i) & 1) != ((y >> i) & 1)) {
            x = x ^ (1 << i);
            y = y ^ (1 << i);
        }
    }
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

void evenOddBit(unsigned long x) {
    if (x & 1) {
        cout << "x: ODD\n";
    } else{
        cout << "x: EVEN\n";
    }

}

int main() {
    cout << "1. Check the least Significant Bit (LSB)\n";
    cout << "2. Check the most significant bit (MSB)\n";
    cout << "3. Check the nth significant bit\n";
    cout << "4. Set the nth bit\n";
    cout << "5. The highest order set bit of a number\n";
    cout << "6. The lowest order set bit of a number\n";
    cout << "7. Count the trailing zeros in binary\n";
    cout << "8. Toggle the nth bit\n";
    cout << "9. Clear the nth bit\n";
    cout << "10. Count the leading zeros\n";
    cout << "11. Flip bits\n";
    cout << "12. Count the number of ones and zeros\n";
    cout << "13. Shift left and right\n";
    cout << "14. Decimal to Binary\n";
    cout << "15. Swap two numbers\n";
    cout << "16. Odd or even\n";

    int choice;
    int nth = 4;
    unsigned long x = 22;
    cin >> choice;
    switch(choice) {
    case 1:
        cout << "LSB of " << x << " is: " << checkLSB(x) << endl;
        break;
    case 2:
        cout << "MSB of " << x << " is: " << checkMSB(x) << endl;
        break;
    case 3:
        cout << nth << "th bit in " << x << " is " << checknthBit(x, nth) << endl;
        break;
    case 4:
        cout << "Setting " << nth << "th bit in " << x << " becomes: " << setnthBit(x, nth) << endl;
        break;
    case 5:
        cout << "Highest bit set in " << x << " is: " << highestOrder(x) << endl;
        break;
    case 6:
        cout << "Lowest bit set in " << x << " is: " << lowestOrder(x) << endl;
        break;
    case 7:
        cout << "The number trailing zeros in " << x << " are: " << countTrailingZero(x) << endl;
        break;
    case 8:
        cout << "Toggling the " << nth << " bit in " << x << ": " << toggleNth(x, nth) << endl;
        break;
    case 9:
        cout << "Clear the " << nth << "th bit in " << x << ": " << clearNth(x, nth) << endl;
        break;
    case 10:
        cout << "The number leading zeros in " << x << " are: " << countLeadingZero(x) << endl;
        break;
    case 11:
        cout << "Flipped bit of " << x << " is: " << flipBits(x) << endl;
        break;
    case 12:
        numZeroOnes(x);
        break;
    case 13:
        cout << "Rotated right two times: " << rotateRight(x) << endl;
        cout << "Rotated left two times: " << rotateLeft(x) << endl;
        break;
    case 14:
        decimalToBinary(x);
        break;
    case 15:
        swapNumbers(x, 50);
        break;
    case 16:
        evenOddBit(x);
        break;
    default:
        break;
    }

    return 0;
}
