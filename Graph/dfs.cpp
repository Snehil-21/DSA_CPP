#include <bits/stdc++.h>
using namespace std;

void insertEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int i, vector<int> adj[], vector<int>& visited) {
    cout<<i<<" ";
    visited[i] = 1;

    for(auto it : adj[i]) {
        if(visited[it] == 0) {
            dfs(it, adj, visited);
        }
    }
}

void printGraph(vector<int> adj[], int v) {
    for(int i = 0; i < v; i++) {
        cout<<i<<" : ";
        for(auto j : adj[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int v;
    cout<<"Enter number of vertices: ";
    cin>>v;

    vector<int> adj[v];

    int e;
    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Enter edges in the format { src dst }\n";
    for(int i = 0; i < e; i ++) {
        int u,v;
        cin>>u>>v;
        insertEdge(u, v, adj);
    }

    // printGraph(adj, v);
    vector<int> visited(v+1, 0);
    for(int i = 0; i < v; i ++)
        if(visited[i] == 0)
            dfs(i, adj, visited);
    return 0;
}