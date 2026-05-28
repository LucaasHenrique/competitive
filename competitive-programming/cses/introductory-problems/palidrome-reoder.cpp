#include <algorithm>
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
    
    string s; cin >> s;
    map<char, int> mp;

    for (auto c: s) mp[c]++;
    int imp = 0;
    for (auto [k, v]: mp) if (v % 2 != 0) imp++;
    
    string r = "";
    if (s.size() % 2 == 0) {
        if (imp > 0) {cout << "NO SOLUTION" << "\n"; return;} 
        
        for (auto [k, v]: mp) mp[k] /= 2; 
        
        for (auto [k, v]: mp) {
            while (mp[k] > 0) {
                r += k;
                mp[k]--;
            }
        }

        string op = r;
        reverse(r.begin(), r.end());
        cout << op + r << "\n";

    } else {
        if (imp >= 2) {cout << "NO SOLUTION" << "\n"; return;}
        
        for (auto [k, v]: mp) {
            if (v % 2 != 0) {
                while (mp[k] > 0) {
                    r += k;
                    mp[k]--;
                }
            }
        }

        for (auto [k, v]: mp) if (v != 0 && v % 2 == 0) mp[k] /= 2;
        
        string op = "";
        for (auto [k, v]: mp) {
            while (mp[k] > 0) {
                op += k;
                mp[k]--;
            }
        }
        string o = op;
        reverse(op.begin(), op.end());
        cout << o + r + op << "\n";
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
