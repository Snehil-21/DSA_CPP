#include <bits/stdc++.h>
using namespace std;

int findElement(int *arr, int n, int k)
{
    priority_queue<int> x;
    for (int i = 0; i < n; i++)
    {
        x.push(arr[i]);
        if (x.size() > k)
        {
            x.pop();
        }
    }
    return x.top();
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
    cout << "Enter k-th position: ";
    int k;
    cin >> k;
    cout << findElement(arr, n, k);
    return 0;
}