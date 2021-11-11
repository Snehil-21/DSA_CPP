#include <bits/stdc++.h>
using namespace std;

// Two Pointers based approach
// Time : O(n)
// Space : O(1)

int celebrity_2pointers(vector<vector<int>> a, int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (a[j][i] == 1)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    int c = i;
    for (int x = 0; x < n; x++)
    {
        if (x != c)
        {
            if (!a[x][c] || a[c][x])
                return -1;
        }
    }
    return c;
}

// Stack based approach
// Time : O(n)
// Space : O(n)

int celebrity_stack(vector<vector<int>> a, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int x = s.top();
        s.pop();
        int y = s.top();
        s.pop();
        if (a[x][y] == 1)
        {
            s.push(y);
        }
        else
        {
            s.push(x);
        }
    }
    if (s.empty())
    {
        return -1;
    }
    else
    {
        int c = s.top();
        for (int i = 0; i < n; i++)
        {
            if (i == c)
            {
                continue;
            }
            if (!a[i][c] || a[c][i])
                return -1;
        }
        return c;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int ans = celebrity_stack(a, n);
    cout << ans;
    int res = celebrity_2pointers(a, n);
    cout << endl
         << res;
    return 0;
}