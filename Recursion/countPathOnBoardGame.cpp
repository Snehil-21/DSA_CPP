#include <bits/stdc++.h>
using namespace std;

int countPaths(int start, int end)
{
    if (start == end)
        return 1;
    if (start > end)
        return 0;

    int pathCount = 0;
    for (int i = 1; i <= 6; i++)
    {
        pathCount += countPaths(start + i, end);
    }

    return pathCount;
}

int main()
{
    cout << countPaths(0, 5);
    return 0;
}