#include <bits/stdc++.h>
using namespace std;

void insertEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfsCycle(int i, vector<int> adj[], vector<int>& visited) {
    queue<pair<int, int>> q;
    q.push({i, -1});
    visited[i] = 1;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int prev = p.second;

        for(auto it : adj[node]) {
            if(visited[it] == 0) {
                visited[it] = 1;
                q.push({it, node});
            }
            else {
                if(prev != it) {
                    return true;
                }
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
            if(bfsCycle(i, adj, visited)) {
                cout<<"Cycle Detected\n";
                return 0;
            }
        }
    }

    cout<<"No Cycle Detected\n";

    return 0;
}