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

bool vis[MAXN][MAXN];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int l, p; 
vector<string> g(p);

int successor[MAXN][MAXN];

bool valido(int x, int y) {
    return !(x >= 0 && x <= p) && !(y >= 0 && y <= l);
}

bool final(int x, int y) {
    if (valido(x, y) && g[x][y] == '.' && y+1==l) return true;
    return false;
}

void back(int x, int y) {
    if (valido(x, y)) {
        pair<int, int> out;
    }
}


void solve() {
    cin >> l >> p;

    
    for (int i = 0; i < l; i++) {
        cin >> g[i];
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
