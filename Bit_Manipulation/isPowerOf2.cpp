#include <iostream>
using namespace std;

int main()
{
    cout << "Enter number: ";
    int x;
    cin >> x;
    if (x && (x & (x - 1)) == 0)
        cout << x << " is a power of 2" << endl;
    else
        cout << x << " is not a power of 2" << endl;
}