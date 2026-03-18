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
#define MAXN 1010

char g[MAXN][MAXN];
int dist[MAXN][MAXN], vis[MAXN][MAXN];
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool val(pair<int, int> s) {
    return s.f >= 0 && s.s >= 0 && s.f <= n && s.s <= n 
        && g[s.f][s.s] != '#' && !vis[s.f][s.s];
}

void bfs_ms(vector<pair<int, int>> ms) {
    memset(vis, 0, sizeof vis);
    memset(dist, INF32, sizeof dist);

    queue<pair<int, int>> q;

    for (auto s: ms) {
        q.push(s);
        vis[s.f][s.s] = 1;
        dist[s.f][s.s] = 0;
    }

    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        for (auto u : mov) {
            u.f += v.f; u.s += v.s;
            if (val(u)) {
                q.push(u);
                vis[u.f][u.s] = 1;
                dist[u.f][u.s] = dist[v.f][v.s] + 1;
            }
        }
    }
} 

int bfs(pair<int, int> s) {
    memset(vis, 0, sizeof vis);

    queue<pair<int, int>> q;
    q.push(s); vis[s.f][s.s] = 1; dist[s.f][s.s] = 0;

    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();

        if (v.f == 0 || v.s == 0 || v.f == - 1 || v.s == m - 1) return dist[v.f][v.s] + 1;

        for (auto u: mov) {
            u.f += v.f; u.s += v.s;
            if (val(u) && dist[v.f][v.s] < dist[u.f][u.s]) {
                q.push(u); vis[u.f][u.f] = 1; dist[u.f][u.s] = dist[v.f][v.s] + 1;
            }
        }
    }

    return -1;
}

void solve() {
    cin >> m >> n;

    vector<pair<int, int>> ms;
    pair<int, int> s;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
        cin >> g[i][j];
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)  {
            if (g[i][j] == '*') ms.pb({i, j});
            if (g[i][j] == '@') s = {i,j};
        }

    bfs_ms(ms);
    int ans = bfs(s);
    
    if (ans == -1) cout << "IMPOSSIBLE" << "\n";
    else cout << ans << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
