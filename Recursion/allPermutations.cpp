#include <bits/stdc++.h>
using namespace std;

void allPermutations(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    // PRINT ALL SUBSTRINGS OF A STRING

    // char ch = s[0];
    // string ros = s.substr(1);
    // allPermutations(ros, ans);
    // allPermutations(ros, ans + ch);

    // PRINT ALL PERMUTATIONS OF A STRING

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string other = s.substr(0, i) + s.substr(i + 1);
        allPermutations(other, ans + ch);
    }
}

int main()
{
    allPermutations("ABC", "");
    return 0;
}