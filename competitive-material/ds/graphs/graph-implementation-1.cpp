#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;
map<int, bool> visited;

void dfs(int u) {

    visited[u] = true;
    cout << u << " ";

    for (int v: graph[u]) {
        if (!visited[v]) dfs(v);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        cout << u << " ";

        for (int v: graph[u]) {
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main (int argc, char *argv[]) {
       
    vector<int> v1 = {1, 1, 2, 2, 3};
    vector<int> v2 = {2, 6, 3, 4, 4};

    vector<pair<int,int>> edges = {
        {1,2}, {1,6}, {2,3}, {2,4}, {3,4}
    };
    
    graph[1] = {2,6};
    graph[2] = {3,4};
    graph[3] = {4};
    graph[4] = {};
    graph[6] = {};

    int n = 6; 
    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));

    mat[1][2] = mat[2][1] = 1;
    mat[1][6] = mat[6][1] = 1;
    mat[2][3] = mat[3][2] = 1;
    mat[2][4] = mat[4][2] = 1;
    mat[3][4] = mat[4][3] = 1;

    
    for (auto [u, v]: edges) {
        cout << u << "--" << v << '\n';
    }
    
    cout << "DFS: ";
    dfs(1);
    cout << "\n";

    visited.clear();
    cout << "BFS: ";
    bfs(1);
    cout << "\n";

    return 0;
}
