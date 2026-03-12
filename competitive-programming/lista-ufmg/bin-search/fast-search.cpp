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

int low_bound(vector<int>& a, int k) {
    int l = 0, r = a.size()-1;

    int ans = -1;
    while (l <= r) {
        int m = (l+r)/2;
        if (a[m] < k) {ans = m; l = m + 1;}
        else r = m - 1;
    }

    return ans;
}

int up_bound(vector<int>& a, int k) {
    int l = 0, r = a.size() - 1;

    int ans = -1;
    while(l <= r) {
        int m = l + (r - l)/2;

        if (a[m] <= k) {ans = m; l = m + 1;}
        else r = m - 1;
    }

    return ans;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    forn(i, n) cin >> a[i]; 
    
    sort(a.begin(), a.end());
    int k; cin >> k;
    while (k--) {
        int l, r; cin >> l >> r;
        cout << up_bound(a, r) - low_bound(a, l) << '\n';
    }

}

// 1 3 4 10 10

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
