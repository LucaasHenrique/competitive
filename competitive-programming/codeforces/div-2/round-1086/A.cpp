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
    
    int n; cin >> n;

    vector<vector<int>> m(n, vector<int>(n)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    bool r = false;
    vector<int> rows(n);
    for (int i = 0; i < n; i++) {
        int f = m[i][0];
        for (int j = 0; j < n; j++) {
            if (m[i][j] == f) r = true; 
            else {r = false; break;}
        }
        
        if (r) rows[i] = 1;
    }
    
    r = false;
    vector<int> cols(n);
    for (int i = 0; i < n; i++) {
        int f = m[0][i];
        for (int j = 0; j < n; j++) {
            if (m[j][i] == f) r = true;
            else {r =false; break;}
        } 
        if (r) cols[i] = 1;
    }
    
    if (cols.empty() && rows.empty()) {cout << "YES" << "\n"; return;}

    for (auto p: rows) cout << "rows: " << p <<"\n";
    for (auto p: cols) cout << "cols: " << p <<"\n";
    
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
