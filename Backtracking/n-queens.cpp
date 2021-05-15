#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** board, int n, int p, int q) {
    
    // Check for rows in the column above the current row
    for(int i = 0; i < p; i++) {
        if(board[i][q] == 1)
            return false;
    }

    int x = p, y = q;

    // Chcek for right upper diagonal
    while(x >= 0 && y < n) {
        if(board[x][y] == 1)
            return false;
        x--;
        y++;
    }

    // Check for left upper diagonal
    x = p, y = q;
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    return true;
}


bool nqueens(int** board, int x, int n) {
    // check if all queens have been placed
    if(x >= n)
        return true;
    
    // if not, continue with the given row
    for(int i = 0; i < n; i++) {
        // iff it is safe to place the queen in row x and column i
        if(isSafe(board, n, x, i)) {
            board[x][i] = 1;
            
            // if this arrangement of queens results in solution, continue
            if(nqueens(board, x+1, n))
                return true;
            
            // else, backtrack to last decision point
            board[x][i] = 0;
        }
    }
    // return false in case of failure
    return false;
}

int main() {
    cout<<"Enter number of queens: ";
    int n; cin>>n;
    int** board = new int* [n];
    for(int i = 0; i < n; i++) {
        board[i] = new int[n];
    }

    // 2D matrix initialisation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }    

    // if queens can be placed successfully
    if(nqueens(board, 0, n)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // not possible to place the queens
    else {
        cout<<"No possible arrangement of "<<n<<"Queens found!";
    }

    return 0;
}