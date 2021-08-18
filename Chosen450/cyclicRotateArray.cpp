#include <bits/stdc++.h>
using namespace std;

void cyclicRotate(int *arr, int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main()
{
    cout << "Enter number of elements in array: ";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cyclicRotate(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}