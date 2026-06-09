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
    int x, n; cin >> x >> n;

    vector<int> a(n);
    
    set<int> pos;
    multiset<ll> values;
    
    pos.insert(0);
    pos.insert(x);
    values.insert(x);

    forn (i, n) {
        int t; cin >> t;

        auto r = pos.upper_bound(t);
        auto l = r; l--;

        values.erase(values.find(*r - *l));
        values.insert(t - *l);
        values.insert(*r - t);

        cout << *values.rbegin() << ' ';

        pos.insert(t);
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
