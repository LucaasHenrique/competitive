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

bool is_short(ll m, ll n, ll t, vector<ll> k) {
    ll sum = 0;  
    forn(i, n) {
        sum += (m / k[i]);
        if (sum >= t) return true;
    }

    return false;
}

    void solve() {
    ll n, t; cin >> n >> t; 
    
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    
    ll min = *min_element(a.begin(), a.end());
    ll l = 0, r = min * t;
    
    ll ans = 1;
    while (l <= r) {
        ll m = (l + r) /2;
        if (is_short(m, n, t, a)) {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    cout << ans << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
