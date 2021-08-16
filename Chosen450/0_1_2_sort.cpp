#include <bits/stdc++.h>
using namespace std;

void sortArray(int *arr, int n)
{
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            one++;
        else
            two++;
    }
    int i = 0;
    while (zero--)
    {
        arr[i] = 0;
        i++;
    }
    while (one--)
    {
        arr[i] = 1;
        i++;
    }
    while (two--)
    {
        arr[i] = 2;
        i++;
    }
}

int main()
{
    cout << "Enter number of elements in array: ";
    int n;
    cin >> n;
    cout << "Enter array elements:\n";
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sortArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}