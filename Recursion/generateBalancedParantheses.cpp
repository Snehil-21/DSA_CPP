#include <bits/stdc++.h>
using namespace std;

void generate(int n, int open, int close, string op){
    if(n==0)
    {
        cout<<op<<endl;
        return;
    }

    if(open==close)
    {
        op.push_back('(');
        generate(n-1,open-1,close,op);
    }

    else if(close > open)
    {
        if(open==0)
        {
            op.push_back(')');
            generate(n-1,open,close-1,op);
            return;
        }
        string op1=op,op2=op;
        op1.push_back('(');
        op2.push_back(')');
        generate(n-1,open-1,close,op1);
        generate(n-1,open,close-1,op2);
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    string op="";
    generate(2*n, n, n, op);
return 0;
}