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
    
    int i = 0, j = 1, k = 0;
    forn (i, n) if (a[i] == 1) a[i]++;
    
    forn(i, n-1) if (a[i+1] % a[i] == 0) a[i+1]++;
    for (auto p: a) cout << p << ' ';

    cout << "\n";
}

//10⁴ * 10⁴ = 10⁸ 

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
