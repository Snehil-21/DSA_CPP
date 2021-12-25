#include <bits/stdc++.h>
using namespace std;

void insertEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfsCheckBipartite(int i, int color, vector<int> adj[], vector<int> coloring) {
    coloring[i] = color;

    for(auto it : adj[i]) {
        if(coloring[it] == coloring[i])
            return false;
        if(coloring[it] == -1)
            if(!dfsCheckBipartite(it, 1-color, adj, coloring)) 
                return false;
    }
    return true;
}

int main() {
    int n;
    cin>>n;

    vector<int> adj[n+1];
    vector<int> coloring(n+1, -1);

    int e;
    cin>>e;

    for(int i = 0; i < e; i++) {
        int u,v;
        cin>>u>>v;
        insertEdge(u, v, adj);
    }

    for(int i = 1; i < n+1; i++) {
        if(coloring[i] == -1) {
            if(dfsCheckBipartite(i, 1, adj, coloring)) {
                cout<<"1\n";
                return 0;
            }
        }
    }
    cout<<"0\n";
    return 0;
}