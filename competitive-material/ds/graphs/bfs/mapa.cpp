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
#define MAXN 110

int n, m;

vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool vis[MAXN][MAXN];
char g[MAXN][MAXN];

bool val(pair<int, int> u) {
    return u.f >= 0 && u.s >= 0 && u.f <= n && u.s <= m
        && g[u.f][u.s] == 'H' && !vis[u.f][u.s]; 
}

pair<int, int> bfs(pair<int, int> s) {
    queue<pair<int, int>> q; 
    q.push(s); vis[s.f][s.s] = 1;

    pair<int, int> v;
    while (!q.empty()) {
        v = q.front(); q.pop(); 
        for (auto u: mov) {
            u.f += v.f; u.s += v.s;  
            if (val(u)) {
                q.push(u); vis[u.f][u.s] = 1;
            }
        }
    }
    
    return v;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
        cin >> g[i][j];

    pair<int, int> s;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
        if (g[i][j] == 'o') s = {i, j}; 

    pair<int, int> ans = bfs(s);

    cout << ans.f + 1 << " " << ans.s + 1  << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
