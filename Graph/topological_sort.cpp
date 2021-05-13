#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    list<int>* adj;
    int n;
    Graph(int n) {
        this->n = n;
        adj = new list<int>[n];
    }
    
    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
    }

    void topologicalSort(int i, vector<bool>& visited, stack<int>& s) {
        visited[i] = true;

        for(auto itr : adj[i]) {
            if(!visited[itr])
                topologicalSort(itr, visited, s);
        }

        s.push(i);
    }

    void topo() {
        vector<bool> visited(n,false);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            if(!visited[i])
                topologicalSort(i, visited, s);
        }

        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

int main() {
    cout<<"Enter number of vertex and edges: ";
    int v,x; cin>>v>>x;
    Graph g(v);
    for(int i = 0; i < x; i++) {
        cout<<"Enter source and destination vertex: ";
        int s,d;
        cin>>s>>d;
        g.addEdge(s,d);
    }
    g.topo();
    return 0;
}