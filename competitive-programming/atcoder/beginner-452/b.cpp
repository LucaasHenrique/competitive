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

void solve() {
    

    int h, w; cin >> h >> w;
    char mat[h][w];

    set<int> rows = {0, h-1};
    set<int> cols = {0, w-1};

    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        mat[i][j] = '.';
    }

    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        if (rows.count(i) || cols.count(j)) mat[i][j] = '#';
    }

    for (int i = 0; i < h; i++){ 
        for (int j = 0; j < w; j++) {
            cout << mat[i][j];
        }
        cout << "\n";
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
