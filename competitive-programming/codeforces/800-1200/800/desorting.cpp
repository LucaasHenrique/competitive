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
    vector<ll> a(n);

    forn(i, n) cin >> a[i];
    
    //cout << 1 << "\n";
    int t = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i+1]) {t = true; break;}
    }
    
    if (t) {cout << 0 << "\n"; return;}

    int minD = INF32;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i+1] - a[i] < minD) {
            minD = a[i+1] - a[i];
            d1 = a[i];
            d2 = a[i+1];
        }
    }   
    
    cout <<  (minD / 2) + 1  << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
