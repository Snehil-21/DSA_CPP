#include <bits/stdc++.h>
using namespace std;

void insertEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool checkBipartite(int i, vector<int> adj[], vector<int> coloring) {
    queue<int> q;
    q.push(i);
    coloring[i] = 1;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto it : adj[curr]) {
            if(coloring[it] == -1) {
                coloring[it] = 1 - coloring[curr];
                q.push(it);
            }
            else if(coloring[it] == coloring[curr]) {
                return false;
            }
        }
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
            if(checkBipartite(i, adj, coloring)) {
                cout<<"1\n";
                return 0;
            }
        }
    }
    cout<<"0\n";
    return 0;
}