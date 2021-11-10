#include <bits/stdc++.h>
using namespace std;

void nextGreaterToLeft(vector<int> &init, vector<int> &final, stack<pair<int, int>> &s)
{
    for (int i = 0; i < init.size(); i++)
    {
        if (i == 0)
        {
            final.push_back(-1);
        }
        else
        {
            while (s.size() > 0 && s.top().first < init[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                final.push_back(-1);
            }
            else
            {
                final.push_back(s.top().second);
            }
        }
        s.push({init[i], i});
    }
}

int main()
{
    vector<int> init;
    int n;
    cout << "Enter number of Stocks: ";
    cin >> n;

    cout << "Enter Stocks: \n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        init.push_back(x);
    }

    stack<pair<int, int>> s;
    vector<int> final;

    nextGreaterToLeft(init, final, s);

    for (int i = 0; i < final.size(); i++)
    {
        cout << i - final[i] << " ";
    }
    cout << endl;
    return 0;
}