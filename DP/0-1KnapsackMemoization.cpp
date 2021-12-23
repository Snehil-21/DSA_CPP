#include <bits/stdc++.h>
using namespace std;

int static memo[1001][1001];

int solve(int wt[], int val[], int w, int n, int memo[][1001]) {
    if(n == 0 || w == 0) {
        return 0;
    }

    if(memo[n][w] != -1)
        return memo[n][w];
    
    int ans;
    if(wt[n] <= w)
        ans = max(solve(wt, val, w-wt[n], n-1, memo) + val[n], solve(wt, val, w, n-1, memo));
    else
        ans = solve(wt, val, w, n-1, memo);

    return memo[n][w] = ans;
}

int main() {
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int w = 7;
    int n = sizeof(wt)/sizeof(wt[0]);
    memset(memo, -1, sizeof(memo));

    int res = solve(wt,val,w,n-1,memo);
    cout<<"Maximum Profit = "<<res<<endl;
    return 0;
}