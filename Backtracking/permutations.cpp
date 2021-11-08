#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

// RECURSIVE PERMUTATION GENERATION
void permute(vector<int> &v, int x)
{
    if (x == v.size())
    {
        ans.push_back(v);
        return;
    }

    for (int i = x; i < v.size(); i++)
    {
        if (i != x && v[i] == v[x])
            continue;
        swap(v[i], v[x]);
        permute(v, x + 1);
        // swap(v[i], v[x]);
    }
}

// STL FUNCTION FOR PERMUTATION GENERATION

void stlpermute(vector<int> &v)
{
    sort(v.begin(), v.end());
    do
    {
        ans.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    sort(v.begin(), v.end());

    permute(v, 0);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}