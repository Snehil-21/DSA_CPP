#include<iostream>
using namespace std;

void dp(int a[], int n, int sum) {
    int t[n+1][sum+1];
    for(int i = 1; i < sum+1; i++)
        t[0][i] = 0;
    for(int i = 0; i < n+1; i++)
        t[i][0] = 1;

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(a[i-1] <= j) {
                t[i][j] = t[i][j-a[i-1]] + t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    cout<<t[n][sum];
}


int main() {
    int n; cin>>n;
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int sum; cin>>sum;
    dp(a, n, sum);
}
