#include <bits/stdc++.h>
using namespace std;

int solve(int wt[], int val[], int w, int n) {
    if(n == 0 || w == 0) {
        return 0;
    }

    int ans;
    if(wt[n] <= w)
        ans = max(solve(wt, val, w-wt[n], n-1) + val[n], solve(wt, val, w, n-1));
    else
        ans = solve(wt, val, w, n-1);

    return ans;
}

int main() {
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int w = 7;
    int n = sizeof(wt)/sizeof(wt[0]);

    int res = solve(wt,val,w,n-1);
    cout<<"Maximum Profit = "<<res<<endl;
    return 0;
}