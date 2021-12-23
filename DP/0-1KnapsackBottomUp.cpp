#include <bits/stdc++.h>
using namespace std;

int solve(int wt[], int val[], int w, int n) {
    int dp[n+1][w+1];

    for(int i = 0; i < n+1; i++) {
        dp[i][0] = 0;
    }

    for(int i = 0; i < w+1; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < w+1; j++) {
            if(wt[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"Filled DP Table for profits at respective weights and items\n";
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < w+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][w];
}

int main() {
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int w = 7;
    int n = sizeof(wt)/sizeof(wt[0]);

    int res = solve(wt,val,w,n);
    cout<<"Maximum Profit = "<<res<<endl;
    return 0;
}