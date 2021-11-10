#include <bits/stdc++.h>
using namespace std;

void nextGreaterToLeft(vector<int> &init, vector<int> &final, stack<int> &s)
{
    for (int i = 0; i < init.size(); i++)
    {
        if (i == 0)
        {
            final.push_back(-1);
        }
        else
        {
            while (s.size() > 0 && s.top() < init[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                final.push_back(-1);
            }
            else
            {
                final.push_back(s.top());
            }
        }
        s.push(init[i]);
    }
}

int main()
{
    vector<int> init;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        init.push_back(x);
    }

    stack<int> s;
    vector<int> final;

    nextGreaterToLeft(init, final, s);

    for (auto i : final)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}