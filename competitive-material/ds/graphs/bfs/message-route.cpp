// question message route - cses
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

vector<int> g[MAXN];
vector<bool> vis(MAXN);
vector<int> pai(MAXN);

void bfs(int s) {
    queue<int> q;
    q.push(s); vis[s] = 1;

    pai[s] = s;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u: g[s]) if (!vis[u]) {
            q.push(u); vis[u] = 1;
            pai[u] = v;
        } 
    }
}


vector<int> path(int v) {
    vector<int> r;
    
    if (!vis[v]) return r;
    
    r.pb(v);
    while (pai[v] != v) {
        v = pai[v];
        r.pb(v);
    }

    reverse(r.begin(), r.end());
    return r;
}

void solve() {
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);
    }

    bfs(1);

    vector<int> ans = path(n);
    
    if (ans.size() == 0) {cout << "IMPOSSIBLE" << "\n"; return;}

    cout << ans.size() << "\n";
    for (auto w: ans) cout << w << " ";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
