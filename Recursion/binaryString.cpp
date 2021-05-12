#include <bits/stdc++.h>
using namespace std;

void generate(int n,string op)
{
    if(n==0)
    {
        cout<<op<<endl;
        return;
    }
    if(op[op.length()-1]=='1')
    {
        op.push_back('0');
        generate(n-1, op);
    }
    else
    {
        string op1 = op;
        string op2 = op;
        op1.push_back('1');
        op2.push_back('0');
        generate(n-1,op1);
        generate(n-1,op2);
    }
    
}

int main() {
    int k=3;
    generate(k,"");
return 0;
}