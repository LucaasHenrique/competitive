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
#define MAXN 300100

vector<int> g[MAXN];
vector<bool> vis(MAXN);
bool cycle = true;

void dfs(int v){
    vis[v] = true;

    if (g[v].size() != 2) {
        cycle = false;
    }

    for (auto w: g[v]) {
        if (!vis[w]) {
           dfs(w);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        g[a].pb(b);
        g[b].pb(a);
    }
    
    vis.assign(MAXN, 0);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]){
            cycle = true;
            dfs(i);

            if (cycle && g[i].size() == 2) {
                c++;
            }
        }
    }

    cout << c << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
