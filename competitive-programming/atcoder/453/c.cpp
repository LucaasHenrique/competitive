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
bool vis[MAXN];

void bfs(int v) {
    queue<int> q;
    q.push(v); vis[v] = 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u: g[v]) {
            if (!vis[u]) {
                q.push(u), vis[u] = true;
            }
        }
    }
}

void solve() {
    
    int n, m; cin >> n >> m;
    forn (i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].pb(b);
    }

    bfs(0);

    int c = 0;
    for (int i = 0; i < n; i++) if (vis[i] == 1) c++;

    cout << c << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
