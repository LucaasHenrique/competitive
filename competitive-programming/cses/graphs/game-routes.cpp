#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
const int maxn = 1e5;

bool visitado[maxn];
vector<int> graph[maxn];

int dfs(int x, int f) {
    visitado[x] = true;
    
    int c = 0;

    for (int v: graph[x]) {
        if (!visitado[x]) dfs(v, x);
        else c++; 
    }

    return c;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        int c = dfs(i, i);
    }

    return 0;
}
