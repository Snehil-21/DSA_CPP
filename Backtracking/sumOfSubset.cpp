#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int a[], int n, int val, vector<int> &v, int sum, int total)
{
    // if value has been generated using a subset, return true
    if (sum == val)
    {
        return true;
    }

    // if no elements left in array, return false
    else if (n < 0)
    {
        return false;
    }

    // if sum has exceeded the value or if value is greater than summation of all elements
    else if (sum + total < val || sum > val)
    {
        return false;
    }

    // push the current element in solution vector
    v.push_back(a[n]);
    if (!subsetSum(a, n - 1, val, v, sum + a[n], total - a[n]))
    {
        // if that branch does not give the solution, backtrack and choose the next element
        v.pop_back();

        //call the function again without considering the current element
        if (subsetSum(a, n - 1, val, v, sum, total - a[n]))
            // return true, if this branch gives the solution
            return true;
    }
    else
    {
        return true;
    }
    // return false in all other cases
    return false;
}

int main()
{
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    int a[n], total = 0;
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    cout << "Enter value to be generated using subset: ";
    int val;
    cin >> val;
    if (val == 0) //if value to be formed is 0, empty subset
    {
        cout << "Empty subset can generate 0";
    }
    else if (n == 0) //if there are no elements in array, value cannot be generated
    {
        cout << "cannot generate any possible sum.";
    }
    else
    {
        vector<int> v;
        if (subsetSum(a, n - 1, val, v, 0, total)) //check for subset possibility
        {
            cout << "Subset Sum generation is possible!\nSubset includes: ";
            reverse(v.begin(), v.end());
            for (auto itr : v)
            {
                cout << itr << " ";
            }
        }
        else
        {
            cout << "cannot generate sum using any subset.\n";
            // for (auto itr : v)
            // {
            //     cout << itr << " ";
            // }
        }
    }
    return 0;
}
