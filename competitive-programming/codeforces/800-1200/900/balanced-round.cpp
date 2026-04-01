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
    
    int n, k; cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    int max_count = 1, c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > k) c = 1;
        else c++;

        max_count = max(max_count, c);
    } 

    cout << n - max_count << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
