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
#define MAXN 100100
    
vector<bool> vis(MAXN);
vector<int> tree[MAXN];
vector<int> a(MAXN);
int n, m; 
int cnt = 0;

void dfs(int v, int p, int c) {
    vis[v] = true;
    if (a[v] == 1) c++;    
    else c = 0;
        
    if (c > m) return;

    bool leaf = true;
    for (auto u: tree[v]) {
        if (u != p) {
            leaf = false;
            dfs(u, v, c);
        } 
    }

    if (leaf) cnt++;
}

void solve() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;

        tree[x].pb(y);
        tree[y].pb(x);
    }
   
    dfs(1, -1, 0);
    cout << cnt << '\n';
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
