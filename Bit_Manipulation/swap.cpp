#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int main()
{
    cout << "Enter number 1: ";
    int a;
    cin >> a;
    cout << "Enter number 2: ";
    int b;
    cin >> b;
    swap(a, b);
    cout << "a = " << a << " b = "
         << " " << b << endl;
    return 0;
}