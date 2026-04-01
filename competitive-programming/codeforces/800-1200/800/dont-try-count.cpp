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
    
    int n, m; cin >> n >> m;
    string x, s; cin >> x >> s;

    int cnt = 0;
    int t = 5;
    bool existe = false;
    
    size_t pos = x.find(s);
    if (pos != string::npos) {cout << cnt << "\n"; return;}
    while (t > 0) {
        x += x;

        size_t pos = x.find(s);

        cnt++;
        if (pos != string::npos) {existe = true; break;}
        t--;
    }
    
    cout << (existe ? cnt : -1) << "\n";
}

// eforc
// force
//
// [2, 5];
// x[1..n] == x[5..n];
//
//aba
//ababa
//1..3
//
//babb
//bbb
//[3...4]
//se x[1..2] contem [3..n];
int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
