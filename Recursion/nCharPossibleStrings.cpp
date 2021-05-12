#include <bits/stdc++.h>
using namespace std;

void printWords(vector<char> v, int n, string op)
{
    if(n==0)
    {
        cout<<op<<endl;
        return;
    }
    for(int i=0;i<v.size();i++)
    {
        string op1 = op + v[i];
        printWords(v, n-1, op1);
    }
}

int main() {
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    int x = 3;
    printWords(v,x,"");
return 0;
}