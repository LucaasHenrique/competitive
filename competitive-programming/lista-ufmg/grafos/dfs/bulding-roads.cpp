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

void dfs(int v) {
    vis[v] = true;

    for (auto u: g[v]) if (!vis[u]) {
        dfs(u);
    }
}

void solve() {
    int n, m; cin >> n >> m; 
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);
    }

    int c = 0;
        
    vector<int> r;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]){r.pb(i); dfs(i); c++;}
    }

    cout << c - 1 << "\n";
    for (int i = r.size()-1; i >= 1; i--) {
        cout << r[i-1] << " " << r[i] << "\n";
    }
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
