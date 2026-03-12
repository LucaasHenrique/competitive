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

int bin_search(vector<int>&a, int k) {
    int l = 0, r = a.size() - 1;

    int res = 0;
    while (l <= r) {
        int m =(r +l) / 2;
        if (a[m] <= k) {
            res = m + 1;
            l = m + 1;
        } else r = m - 1;
    }

    return res;
}   

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    forn(i, n) cin >> a[i]; 
    while (k--) {
        int h; cin >> h;
        cout << bin_search(a, h) << "\n";
    } 
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
