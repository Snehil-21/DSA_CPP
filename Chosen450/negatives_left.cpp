#include <iostream>
using namespace std;

void negativesLeft(int *arr, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            left++;
            right--;
        }
        else if (arr[left] < 0 && arr[right] > 0)
        {
            left++;
        }
        else if (arr[left] < 0 && arr[right] < 0)
        {
            left++;
        }
        else if (arr[left] > 0 && arr[right] > 0)
        {
            right--;
        }
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
    negativesLeft(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}