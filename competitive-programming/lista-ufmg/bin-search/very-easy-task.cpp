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

bool bin_s(int n, int x, int y, ll k) {
    ll res = (k / x) + (k / y);
    return res >= n - 1;
}    

void solve() {
    int n, x, y; cin >> n >> x >> y;
    
    ll l = 0, r = 1e9;
    int ans = -1;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (bin_s(n, x, y, m)) {
            ans = m;
            r = m-1;
        } else l = m+1;
        cout << ans << "\n";
    }

    cout << ans + min(x, y) << "\n";
}

// 4 copias, maquina 1 -> 1 sec | maquina 2 -> 1 sec
// inicialmente só tenho um papel então posso usar apenas uma maquina.

// 1 copia - 1 sec
// 2 copia - 2 sec
// 4 copias - 3 sec
// 5 copias - 4 sec
// total = 4 secs

// 1 copia - 1sec
// 2 copias - 2 sec
// 3 copias - 3 sec
// 5 copias - 4 secs

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
