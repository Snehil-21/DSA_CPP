#include<iostream>
using namespace std;

void dp(int a[], int n, int sum) {
    int memo[n+1][sum+1] = {0};
    for(int i = 1; i < sum+1; i++) {
        memo[0][i] = 0;
    }
    for(int i = 0; i < n+1; i++) {
        memo[i][0] = 1;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(a[i-1] <= j) {
                memo[i][j] = memo[i-1][j] + memo[i-1][j-a[i-1]];
            }
            else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    cout<<memo[n][sum];
}

int main() {
    cout<<"Number of elements: ";
    int n; cin>>n;
    cout<<"Elements:\n";
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<"Sum: ";
    int sum; cin>>sum;
    dp(a, n, sum);
    return 0;
}