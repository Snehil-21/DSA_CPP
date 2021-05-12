#include <bits/stdc++.h>
using namespace std;

void letterCaseChange(string ip, string op) {
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(ip[0]);
    op1.push_back(ip[1]);
    if(ip[0]<=90&&ip[0]>=65)
    op2.push_back(tolower(ip[0]));
    else
    op2.push_back(toupper(ip[0]));
    op2.push_back(ip[1]);
    ip.erase(ip.begin()+0);
    ip.erase(ip.begin()+0);
    letterCaseChange(ip, op1);
    letterCaseChange(ip, op2);
}
int main() {
    letterCaseChange("a1B2", "");
    return 0;
}