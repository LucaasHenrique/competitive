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

void back(string s, int n) {
    int z = 0, o = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') z++;
        if (s[i] == '1') o++;
    }

    if (z < o && z + n <= o) return;

    if (n == 0) {cout << s << "\n"; return;}
    
    back(s+'1', n-1);
    back(s+'0', n-1);
}

void solve() {
    int n; cin >> n;
    string s = "";
    back(s, n);
} 

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
