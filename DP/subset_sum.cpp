#include<iostream>
using namespace std;

void dp(int* a, int n, int sum) {
    bool memo[n+1][sum+1];
    for(int i = 0; i < sum+1; i++) {
        memo[0][i] = false;
    }
    for(int i = 0; i < n+1; i++) {
        memo[i][0] = true;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(a[i-1] <= j) {
                memo[i][j] = memo[i-1][j] || memo[i-1][j-a[i-1]];
            }
            else
                memo[i][j] = memo[i-1][j];
        }
    }
    if(memo[n][sum])
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
}

int main() {
    cout<<"Enter number of elements in the set: ";
    int n; cin>>n;
    int* a = new int[n];
    cout<<"Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<"Enter the sum to be formed: ";
    int sum; cin>>sum;
    dp(a, n, sum);

    /* for EQUAL SUM PARTITION, just pass SUM/2 to dp function and before that 
     check if sum of array elements is even! */

    return 0;
}