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

    map<int, int> oc;
    forn(i, n) {int c; cin >> c; oc[c]++;}

    if (oc.size() >= 3) cout << "no" << "\n";
    else {
        // verifico a diferença entre o primeiro e o ultimo valor de map!!!!
        if (abs(oc.begin()->second - oc.rbegin()->second) <= 1) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
