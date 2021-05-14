#include <bits/stdc++.h>
using namespace std;

int DP[10001][10001];

int mcm(int mat[], int i, int j) {
    if(i >= j)
        return 0;

    if(DP[i][j] != -1)
        return DP[i][j];
    
    DP[i][j] = INT_MAX;

    for(int k = i; k < j; k++) {
        DP[i][j] = min(DP[i][j], mcm(mat,i,k) + mcm(mat,k+1,j) + mat[i-1] * mat[k] * mat[j]);
    }
    return DP[i][j];
}


int main(){
    cout<<"Enter number of matrices: ";
    int n; cin>>n;
    int* mat = new int[n+1];

    cout<<"Enter matrix dimensions: ";
    for(int i = 0; i < n+1; i++) {
        cin>>mat[i];
    }
    memset(DP, -1, sizeof(DP));

    cout<<"Minimum cost of multiplication of matrices is: "<<mcm(mat, 1, n);
    return 0;
}