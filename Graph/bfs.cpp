#include <bits/stdc++.h>
using namespace std;

void insertEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int v, vector<int> adj[]) {
    int visited[v] = {0};
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(visited[i] == 0) {
            q.push(i);
            visited[i] = 1;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                cout<<curr<<" ";
                for(auto j : adj[curr]) {
                    if(visited[j] == 0) {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
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
    bfs(v, adj);

    return 0;
}