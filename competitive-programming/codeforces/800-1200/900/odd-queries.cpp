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
    
    int n, q; cin >> n >> q;
    vector<int> a(MAXN);

    int pref[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1];
        pref[i] += a[i];
    }
    

    while (q--) {
        ll l, r, k; cin >> l >> r >> k;

        ll ans = pref[n] - (pref[r] - pref[l-1]) + k * (r - l + 1);

        if (ans % 2 == 0) cout << "NO" << '\n';
        else cout << "YES" << "\n";
    }
    
}

// para saber a soma total de intervalo [l, r] no arary original, faço pref[r] - pref[l-1];

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
