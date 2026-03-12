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
vector<int> sub_size(MAXN);

void dfs(int v) {
    sub_size[v] = 1;
    for (auto u: g[v]) {
        dfs(u);
        sub_size[v] += sub_size[u];
    }
}

void solve() {
    
    int n; cin >> n;

    for (int i = 2; i <= n; i++) {
        int a; cin >> a;

        g[a].pb(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub_size[i] - 1 << " ";
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
