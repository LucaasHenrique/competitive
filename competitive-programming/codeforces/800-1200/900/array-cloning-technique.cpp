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
    
    map<int, int> mc;
    forn (i, n) {cin >> a[i]; mc[a[i]]++;}

    int max_occ = 0;
    for (auto a: mc) if (a.second > max_occ) max_occ = a.second;

    int op = 0;
    while (max_occ < n) {
        op++;
        // increment all copies
        if (max_occ * 2 <= n) {
            op += max_occ;
            max_occ *= 2;
        } else { // increment some copies
            op += n - max_occ;
            max_occ = n; 
        }
    }

    cout << op << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
