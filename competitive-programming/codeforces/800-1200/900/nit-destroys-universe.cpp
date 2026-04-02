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
    forn (i, n) cin >> a[i];
    
    int zero = false;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) zero = true;
    }
    
    if (!zero) cout << 0 << "\n"; 
    else {
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {l = i; break;}
    }

    for (int i = n-1; i > 0; i--) {
        if (a[i] != 0) {r = i; break;}
    }
    
    //cout << l << " " << r;
    for (int i = l; i <= r; i++) {
        if (a[i] == 0) {cout << 2 << "\n"; return;}
    }

    cout << 1 << "\n";
    }
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
