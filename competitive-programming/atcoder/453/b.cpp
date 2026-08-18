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
    
    int n, m; cin >> n >> m;
    map<int, int> f;
    set<int> fx;
    
    forn (i, n) {
        int x; cin >> x;
        f[x]++;
        fx.insert(x);
    }
    
    string ans1 = "Yes";
    for (auto [k, v] : f) {
        if (v >= 2) {ans1 = "No"; break;}
    }

    string ans2 = "Yes";
    for (int i = 1; i <= m; i++) {
        if (!fx.count(i)) {ans2 = "No";}
    }

    cout << ans1 << "\n" << ans2 << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
