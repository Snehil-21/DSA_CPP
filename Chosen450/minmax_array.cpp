#include <iostream>
using namespace std;

class MinMax
{
public:
    int min;
    int max;
};

MinMax getResult(int *arr, int n)
{
    MinMax p;
    int i;
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            p.max = arr[0];
            p.min = arr[1];
        }
        else
        {
            p.max = arr[1];
            p.min = arr[0];
        }
        i = 2;
    }
    else
    {
        p.max = arr[0];
        p.min = arr[0];
        i = 1;
    }

    while (i < n - 1)
    {
        if (arr[i] < arr[i + 1])
        {
            if (arr[i] < p.min)
            {
                p.min = arr[i];
            }
            if (arr[i + 1] > p.max)
            {
                p.max = arr[i + 1];
            }
        }
        else
        {
            if (arr[i] > p.max)
            {
                p.max = arr[i];
            }
            if (arr[i + 1] < p.min)
            {
                p.min = arr[i + 1];
            }
        }
        i += 2;
    }
    return p;
}

int main()
{
    cout << "Enter number of elements in array: ";
    int n;
    cin >> n;

    int *arr = new int[n];
    cout << "Enter array elements separated by space\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MinMax m = getResult(arr, n);
    cout << "Max: " << m.max << " "
         << "\nMin: " << m.min;
    return 0;
}