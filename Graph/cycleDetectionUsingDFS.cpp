#include <bits/stdc++.h>
using namespace std;

void insertEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfsCycle(int i, int j, vector<int> adj[], vector<int>& visited) {
    visited[i] = 1;
    // cout<<i<<" "<<j<<endl;
    for(auto it : adj[i]) {
        // cout<<it<<endl;
        if(visited[it] == 0) {
            if(dfsCycle(it, i, adj, visited)) {
                return true;
            }
        }
        else {
            if(j != it) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v;
    cout<<"Enter number of vertices: ";
    cin>>v;

    vector<int> adj[v+1];

    int e;
    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Enter edges in the format { src dst }\n";
    for(int i = 0; i < e; i ++) {
        int u,v;
        cin>>u>>v;
        insertEdge(u, v, adj);
    }

    vector<int> visited(v+1, 0);
    for(int i = 1; i < v+1; i++) {
        if(visited[i] == 0) {
            if(dfsCycle(i, -1, adj, visited)) {
                cout<<"Cycle Detected\n";
                return 0;
            }
        }
    }

    cout<<"No Cycle Detected\n";

    return 0;
}