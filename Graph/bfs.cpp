#include <bits/stdc++.h>
using namespace std;

// Add edge in adj list
void addEdge(int x, int y, list<int> adj[]) {
    adj[x].push_back(y);
}


// Print edges of graph
void showEdges(int n, list<int> adj[]) {
    for(int i = 0; i < n; i++) {
        cout<<i<<" -> ";
        for(auto j : adj[i]) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}


// BFS HELPER FUNCTION
void bfsUtil(vector<int>& visited, int n, int src, list<int> adj[]) {
    queue<int> q;

    q.push(src);
    visited[src] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        for(auto i : adj[x]) {
            if(visited[i] == 0) {
                // cout<<"i: "<<i<<endl;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

// BFS FUNCTION
void bfs(int n, int src, list<int> adj[]) {
    vector<int> visited(n,0);

    bfsUtil(visited, n, src, adj);

    for(int i = 0; i < n; i++) {
        // cout<<"Entered for loop\n i= "<<i<<"\n";
        if(visited[i] == 0) {
            bfsUtil(visited, n, i, adj);
        }
    }
}

// UTIL FUNCTION FOR DFS
void dfsUtil(vector<bool>& visited, list<int> adj[], int i) {
    cout<<i<<" ";
    visited[i] = true;

    for(auto x : adj[i]) {
        if(visited[x] == false) {
            dfsUtil(visited, adj, x);
        }
    }
}


// DFS FUNCTION
void dfs(int n, list<int> adj[]) {
    vector<bool> visited(n,false);

    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            dfsUtil(visited, adj, i);
        }
    }
}

int main() {
    int n,e;
    cout<<"Enter number of Nodes: ";
    cin>>n;
    cout<<"Enter number of Edges: ";
    cin>>e;

    list<int> adj[n];
    cout<<"Enter edges in format {source} {destination}\n";
    for(int i = 0; i < e; i++) {
        int x,y; cin>>x>>y;
        addEdge(x,y, adj); 
    }
    // showEdges(n, adj);
    
    // cout<<"Enter Source vertex: ";
    // int src; cin>>src;
    // bfs(n, src, adj);

    dfs(n, adj);
    return 0;
}