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
    
    ll n; cin >> n; 
    ll cost = 0;
    vector<ll> a(n);
    ll sum = 0;
    forn (i, n) {cin >> a[i]; sum += a[i];}
    
    sort(a.begin(), a.end());
    sum = a[n/2];
    //cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        cost += abs(a[i] - sum);
    }
    
    cout << cost << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
