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

    int c = 0;
    forn(i, n) cin >> a[i]; 
    int m = *max_element(a.begin(), a.end());

    forn(i, n) if (a[i] == m) c++;
    
    cout << c << "\n";
}

// 4
// 1 4 3 4
// 0 3 2 3
// 0 2 1 2
// 0 1 0 1
// 0 0 0 0

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
