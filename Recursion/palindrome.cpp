#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int n) {
    static int sum=0;
    if(n<=0)
    return 1;
    int x = n%10;
    sum = sum*10+x;
    isPalindrome(n/10);
    return sum;
}

int main() {
    cout<<"Enter number: ";
    int x;
    cin>>x;
    isPalindrome(x)==x?cout<<"YES":cout<<"NO";
return 0;
}