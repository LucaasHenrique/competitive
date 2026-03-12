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

    ll m = 1ll * n * (1ll * 1 + n) / 2;
    if (m % 2 != 0) {cout << "NO" << "\n"; return;}

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i+1;

    cout << "YES" << '\n';

    vector<int> s1, s2;
    vector<bool> vis(n+1, 0);
    
    ll sum1 = 0;
    ll max_e = n;
    
    while (sum1 < m / 2) {
        
        ll remaining_sum = m / 2 - sum1;

        if (remaining_sum > max_e) {
            s1.pb(max_e);
            vis[max_e] = 1;
            sum1 += max_e;
            max_e--;
        } else {
            s1.pb(remaining_sum); 
            vis[remaining_sum] = 1;
            sum1 = m / 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            s2.pb(i);
        }
    }

    cout << s1.size() << "\n";
    for (auto e: s1) cout << e << " ";
    cout << '\n';

    cout << s2.size() << "\n";
    for (auto e: s2) cout << e << " ";
    cout << '\n';
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
