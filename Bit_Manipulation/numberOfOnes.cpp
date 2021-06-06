#include <iostream>
using namespace std;

int numOfOnes(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of Ones: " << numOfOnes(n) << endl;
}