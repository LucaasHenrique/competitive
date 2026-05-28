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
    vector<pair<ll, ll>> p;
    int nn = n;
    while (n--) {
        ll a, b; cin >> a >> b;
        p.pb({a, b});
    }

    sort(p.begin(), p.end());
    
    vector<ll> pref(nn);
    pref[0] = p[0].f;
    for (int i = 1; i < nn; i++) {
        pref[i] = pref[i-1] + p[i].f;
    }
    
    ll sum = 0;
    for (int i = 0; i < nn; i++) {
        sum += p[i].s - pref[i];
    }
    cout << sum << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
