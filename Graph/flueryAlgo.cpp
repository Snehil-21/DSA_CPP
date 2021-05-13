#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int n;
    list<int>* adj;
    Graph(int v) {
        n = v;
        adj = new list<int>[n];
    }
    
    // add edge in graph
    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    // check connected graph using one DFS
    void DFS(int i, vector<bool>& visited) {
        visited[i] = true;
        for(auto it : adj[i]) {
            if(!visited[it])
                DFS(it, visited);
        }
    }

    // whether it is connected or not
    bool isGraphConnected() {
        int i;
        vector<bool> visited(n, false);
        for(i = 0; i < n; i++) {
            if(adj[i].size() > 0)
                break;
        }

        DFS(i, visited);

        for(int i = 0; i < n; i++) {
            if(!visited[i] && adj[i].size() > 0)
                return false;
        }
        return true;
    }

    // check if it is eulerian or not
    void findEulerian() {
        bool ans = isGraphConnected();
        if(ans == false) {
            cout<<"Not Eulerian\n";
            return;
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(adj[i].size() & 1)
                count++;
        }
        if(count > 2)
            cout<<"Not Eulerian\n";
        else if(count == 0) {
            cout<<"Graph has Eulerian Circuit\n";
        }
        else if(count == 2) {
            cout<<"Graph has Eulerian Path\n";
        }
    }
};

int main() {
    cout<<"Enter number of Vertices: ";
    int v; cin>>v;
    cout<<"Enter number of Edges: ";
    int n; cin>>n;
    if(n == 0) {
        cout<<"Eulerian Graph\n";
        return 0;
    }
    Graph g(v);
    for(int i = 1; i <= n; i++) {
        int s,d;
        cout<<"Enter source and destination "<<i<<": ";
        cin>>s>>d;
        g.addEdge(s,d);
    }
    g.findEulerian();
    return 0;
}