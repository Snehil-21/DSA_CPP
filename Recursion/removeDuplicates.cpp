#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    if (s.length() == 0)
        return "";

    char ch = s[0];
    string str = removeDuplicates(s.substr(1));
    if (str[0] == ch)
        return str;
    else
        return (ch + str);
}

int main()
{
    string s = "aabchddddadfnnsfgddfgs";
    cout << removeDuplicates(s);
    return 0;
}