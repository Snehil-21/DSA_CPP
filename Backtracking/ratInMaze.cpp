#include <bits/stdc++.h>
using namespace std;

bool isValid(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] != 0)
        return true;
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **res)
{
    if (x == n - 1 && y == n - 1)
    {
        res[x][y] = 1;
        return true;
    }

    if (isValid(arr, x, y, n))
    {
        res[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, res))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, res))
        {
            return true;
        }
        res[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **res = new int *[n];
    for (int i = 0; i < n; i++)
    {
        res[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, res))
    {
        cout << "Solution path : \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    else
    {
        cout << "No solution path exists\n";
    }

    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1