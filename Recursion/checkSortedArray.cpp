#include <bits/stdc++.h>
using namespace std;

bool sortedArrayCheck(int arr[], int n)
{
    if (n == 1)
        return true;

    bool restArray = sortedArrayCheck(arr + 1, n - 1);
    if (arr[0] < arr[1] && restArray)
        return true;
    return false;
}

int main()
{
    int arr[] = {20, 10, 30, 40, 50};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << sortedArrayCheck(arr, len);
    return 0;
}