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

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int pmax = 0, pmin = INF32;
    int posm = 0, posmin = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= pmin) {pmin = a[i]; posmin = i;}
        if (a[i] > pmax) {pmax = a[i]; posm = i;}
    }

    if (posm > posmin) cout << (n - posmin - 1) + (posm) - 1; 
    else cout << posm + ((n -1) - posmin);
}

// 33 44 11 22
// 0  1   2  3

// 10 10 58 31 63 40 76
// 0  1   2 3  4  5   6
//

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

// 10 // 78
// 5 // 6
//
