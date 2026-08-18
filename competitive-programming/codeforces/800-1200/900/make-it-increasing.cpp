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
    vector<ll> a(n);

    forn(i, n) cin >> a[i];
   
    int c = 0;
    int t = 30 * 4;
    while (t--) {
       for (int i = n-1; i >= 1; i--) {
             if (a[i] <= a[i-1]) {
               a[i-1] = a[i-1] / 2;   
               c++;
          }
       }
    }

    map<ll, ll> mp;

    for (auto p: a) mp[p]++;
    for (auto p: mp) if (p.second > 1) {cout << -1 << "\n"; return;} 
        
    cout << c << '\n';
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
