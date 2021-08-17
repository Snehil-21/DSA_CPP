#include <bits/stdc++.h>
using namespace std;

void unionOf2Arrays(int *a, int *b, int n, int m)
{
    set<int> s;
    int i = 0;
    for (i = 0; i < min(n, m); i++)
    {
        s.insert(a[i]);
        s.insert(b[i]);
    }
    if (i != n)
    {
        for (i = m; i < n; i++)
        {
            s.insert(a[i]);
        }
    }
    else
    {
        for (i = n; i < m; i++)
        {
            s.insert(b[i]);
        }
    }
    cout << "Size of union set: " << s.size() << endl;
    for (auto it : s)
    {
        cout << it << " ";
    }
}

int main()
{
    cout << "Enter number of elements in array 1: ";
    int n;
    cin >> n;
    int *a = new int[n];
    cout << "Enter number of elements in array 2: ";
    int m;
    cin >> m;
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *b = new int[m];

    cout << "Enter array elements:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    unionOf2Arrays(a, b, n, m);
    return 0;
}