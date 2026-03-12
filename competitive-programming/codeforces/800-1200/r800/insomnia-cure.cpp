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

set<int> a;

void ans(int d, int n) {
    for (int i = n; i <= d; i += n) a.insert(i);
}

void solve() {
    int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
    
    ans(d, k); ans(d, l); ans(d, m); ans(d, n);

    cout << a.size() << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
