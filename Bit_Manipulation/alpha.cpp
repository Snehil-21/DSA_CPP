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

void toggleBit(int num, int i)
{
    num = num ^ (1 << i);
    cout << "Number after toggling bit is: " << num << endl;
}

void upperCase()
{
    char ch;
    cout << "Enter character to convert: ";
    cin >> ch;
    ch = ch | (1 << 5);
    cout << "Character after conversion: " << ch << endl;
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
    toggleBit(num, i);
    upperCase();
}