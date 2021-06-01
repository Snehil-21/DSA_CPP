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
    cout << "Updated number is " << num << endl;
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
}