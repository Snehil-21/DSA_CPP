// KADANE ALGORITHM

#include <bits/stdc++.h>
using namespace std;

void kadane(int *arr, int n)
{
    int local_max = 0, global_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        local_max = arr[i] + local_max;
        if (local_max > global_max)
        {
            global_max = local_max;
        }
        if (local_max < 0)
        {
            local_max = 0;
        }
    }
    cout << "Maximum sum contiguous subarray: " << global_max;
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
    kadane(arr, n);
    return 0;
}