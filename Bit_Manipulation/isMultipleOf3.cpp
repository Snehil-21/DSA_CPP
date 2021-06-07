#include <iostream>
using namespace std;

void isMultipleOf3(int n)
{
    int even = 0, odd = 0;
    if (n < 0)
        n = -n;
    if (n == 0)
    {
        cout << "Multiple of 3\n";
        return;
    }
    if (n == 1)
    {
        cout << "Not a multiple of 3\n";
        return;
    }

    while (n > 0)
    {
        if (n & 1)
            odd++;

        if (n & 2)
            even++;
        n = n >> 2;
    }
    if (abs(even - odd) % 3 == 0)
        cout << "Multiple of 3\n";
    else
        cout << "Not a multiple of 3\n";
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    isMultipleOf3(n);
    return 0;
}