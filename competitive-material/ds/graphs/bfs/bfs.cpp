#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (ll i = 0; i < n; i++)
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
#define MAXN 300100

vector<bool> vis(MAXN);
vector<int> g[MAXN];

//distancia de um vertice ate s
vector<int> dist(MAXN, -1);

void bfs(int s) {
    queue<int> q;
    q.push(s), vis[s] = 1;


    dist[s] =0;
    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (auto u: g[v]) if (!vis[u]) {
            dist[u] = dist[v] + 1;
            q.push(u), vis[u] = 1;
        }
    }
}

void solve() {
        
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
