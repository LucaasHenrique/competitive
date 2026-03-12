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

vector<int> g[MAXN];

void solve() {
    int n; cin >> n;

    vector<int> from(101), to(101);
    
    int cost = 0, t_cost = 0;  
    for (int i = 1; i <= n; i++) {
        int a, b, c; cin >> a >> b >> c;

        t_cost += c;
        if (from[a] || to[b]) {
            from[b] = 1;
            to[a] = 1;
            cost += c;
        } else {from[a] = 1; to[b] = 1;}
    }
    
    cout << min(cost, t_cost - cost); 
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
