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
    int x, k; cin >> x >> k;
    
    int x0 = 0;
    int d1 = 0, d2 = 0;
    if (x % k != 0) {
        cout << 1 << "\n";
        cout << x << "\n"; return;
    }
    
    for (int i = 0; i <= x; i++) {
        if (abs(x0 - i) % k != 0 && abs(i - x) % k != 0) {
            d1 = abs(x0 - i);
            d2 = abs(i - x);
            break;
        }
    }
    
    cout << 2 << "\n";
    cout << d1 << " " << d2 << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
