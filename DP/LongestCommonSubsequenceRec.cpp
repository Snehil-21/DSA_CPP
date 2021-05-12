#include<bits/stdc++.h>
using namespace std;

int LCS(string& x, string& y, int a, int b) {
    // if either of the string has length 0, return 0
    if(a==0 || b==0) { 
        return 0;
    }

    int DP[a+1][b+1];

    for(int i = 0; i < a+1; i++) {
        for(int j = 0; j < b+1; j++) {
            if(i == 0 || j == 0)
                DP[i][j] = 0;    //fill row 0 and column 0 with 0
            else if (x[i-1] == y[j-1]) 
                DP[i][j] = 1 + DP[i-1][j-1];   //add 1 if letters match
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);   //find the maximum of both with 1 less letter in the string
        }
    }

    string str = "";
    int i = a, j = b;
    while(i > 0 && j > 0) {
        if(x[i-1] == y[j-1]) {
            str = x[i-1] + str;
            i--;
            j--;
        }
        else if(DP[i-1][j] > DP[i][j-1]) {
            i--;
        }
        else
            j--;
    }

    cout<<"LCS characters: "<<str<<endl;
    return DP[a][b];

    // if(x[a-1] == y[b-1])
    //     return 1+LCS(x,y,a-1,b-1);
    // else
    //     return max(LCS(x,y,a-1,b), LCS(x,y,a,b-1));
}

int main() {
    string s1,s2; 
    cout<<"Enter first string: ";
    cin>>s1;
    cout<<"Enter second string: ";
    cin>>s2;
    int l1 = s1.length(), l2 = s2.length();
    int x = LCS(s1,s2,l1,l2);
    cout<<"LCS Length: "<<x;
    return 0;
}