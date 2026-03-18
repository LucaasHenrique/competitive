#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue
#define maxn 5050

int n = 4;
int m = 4;
vector<int> graph[maxn];
bool visitado[maxn];

void dfs(int x) {
    visitado[x] = true;
    //cout << x << " ";

    for (int v: graph[x]) {
        if (!visitado[v]) dfs(v);
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= n; i++) visitado[i] = false;
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            c++;
            dfs(i);
        }
    }
    

    cout << c << "\n";
    return 0;
}
