#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int a[], int n, int val, vector<int> &v, int sum, int total) {
    if(sum == val) {
        return true;    
    }
    
    else if(n < 0) {
        return false;
    }

    else if(sum + total < val || sum > val) {
        return false;
    }

    v.push_back(a[n]);
    if(!subsetSum(a, n-1, val, v, sum+a[n], total-a[n])) {
        v.pop_back();
        if(subsetSum(a, n-1, val, v, sum, total-a[n]))
            return true;
    }
    else {
        return true;
    }
    return false;
}

int main() {
    int n; cin>>n;
    int a[n], total = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        total += a[i];
    }

    int val; cin>>val;
    if(val == 0) {
        cout<<"Empty subset can generate 0";
    }
    else if(n == 0) {
        cout<<"cannot generate any possible sum.";
    }
    else {
        vector<int> v;
        if(subsetSum(a, n-1, val, v, 0, total)) {
            cout<<"Subset Sum generation is possible!\nSubset includes: ";
            for(auto itr : v) {
                cout<<itr<<" ";
            }
        }
        else {
            cout<<"cannot generate sum using any subset.\n";
            for(auto itr : v) {
                cout<<itr<<" ";
            }
        }
    }
    return 0;
}
