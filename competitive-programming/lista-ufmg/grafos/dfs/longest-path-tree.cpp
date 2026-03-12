#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 30000100

vector<vector<int>> g(MAXN);
int dist[MAXN];

int dfs(int v) {
   for (auto w: g[v]) if (dist[w] == -1) {
       dist[w] = dist[v] + 1;
       dfs(w);
   } 
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    memset(dist, -1, sizeof dist);
    
    for (int i = 0; i < n; i++) {

    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
