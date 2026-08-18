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

    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; a--; b--;
        ps.pb({a, b});
    }

    int m; cin >> m;
    vector<string> t;
    for (int i = 0; i <m; i++) {
        string s; cin >> s; t.pb(s);
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
