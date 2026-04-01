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
    
    ll a, b, n; cin >>  a >> b >> n;
    vector<ll> v(n);
    
    for (int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    ll ans = b;
    for (int i = 0; i < n; i++) {
       ans += min(a - 1, v[i]); 
    }

    cout << ans << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
