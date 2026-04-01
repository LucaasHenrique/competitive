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
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j  = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> g;
    set<int> log;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!log.count(a[i][j])) {
                g.pb(a[i][j]); sum += a[i][j];
            }
            log.insert(a[i][j]);
        }
    }
    
    int b = 2*n*(2*n+1)/2;
    cout << b - sum << " ";
    for (auto k: g) cout << k << " ";

    cout << "\n";

}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

