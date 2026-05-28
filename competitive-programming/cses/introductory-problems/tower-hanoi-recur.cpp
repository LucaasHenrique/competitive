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

void th(int n, vector<pair<int, int>>& m, int s, int e, int a)  {
    
    if (n == 1) {m.pb({s, e}); return;}

    th(n-1, m, s, a, e);

    m.pb({s, e});

    th(n-1, m, a, e, s);
}

void solve() {
        
    int n; cin >> n; 
    vector<pair<int, int>> m; 
    th(n, m, 1, 3, 2);
    
    cout << m.size() << "\n";
    for (auto [k, v]: m) cout << k << " " << v << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
