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
    string s; cin >> s;

    map<char, int> mp; 

    for (int i = 0; i < n; i++) mp[s[i]]++;
    int impar = 0;
    
    for (auto [kk, v]: mp) {
        if (v % 2 !=  0) impar++;
    }

    impar--;
    if (impar <= k) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
