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
    
    ll x, n; cin >> x >> n;
    
    ll ans;
    if (n % 4 == 0) ans = 0;
    else if (n % 4 == 1) ans = -n;
    else if (n % 4 == 2) ans = 1;
    else if (n % 4 == 3) ans = n + 1;
    
    if (x % 2 == 0) ans = x + ans;
    else ans = x - ans;
    
    cout << ans << "\n";
}

// 0  1  2  3  4  5  6  7  8  9  10  11  12
// 0     

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
