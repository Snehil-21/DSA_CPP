#include <iostream>
using namespace std;

void getBit(int num, int i)
{
    bool x = (num & (1 << i));
    cout << "Bit at position " << i << " is " << x << endl;
}

void setBit(int num, int i)
{
    num = num | (1 << i);
    cout << "Updated number after setting bit is " << num << endl;
}

void clearBit(int num, int i)
{
    num = num & (~(1 << i));
    cout << "Updated number after clearing bit is: " << num << endl;
}

int main()
{
    int num, i;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter position: ";
    cin >> i;
    getBit(num, i);
    setBit(num, i);
    clearBit(num, i);
}