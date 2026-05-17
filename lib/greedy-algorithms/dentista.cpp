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

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.s < b.s;
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> p;
    int o = n;
    while (n--) {
        int x, y; cin >> x >> y;
        p.pb({x, y});
    }
    
    sort(p.begin(), p.end(), comp);
    
    int t = 1;
    int x = p[0].f, y = p[0].s;
    for (int i = 1; i < o; i++) {
        if (p[i].f >= y) {
            t++;
            y = p[i].s;
        } 
    }

    cout << t << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
