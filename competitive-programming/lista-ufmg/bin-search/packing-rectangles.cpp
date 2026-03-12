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

// dado o maior tamanho de lado r, verificar se a quantidade de quadrados que cabem nesse tamanho r é >= N;

bool is_valid(ll w, ll h, ll n, ll r) {
    return (r / h) * (r / w) >= n;
}

void solve() {
    
    ll w, h, n; cin >> w >> h >> n;
    
    ll l = 0, r = 1;
    
    while (!is_valid(h, w, n, r)) r *= 2;

    ll ans = 0;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (is_valid(w, h, n, m)) r = m;
        else l =m + 1;
    }

    cout << l << "\n";
}



int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
