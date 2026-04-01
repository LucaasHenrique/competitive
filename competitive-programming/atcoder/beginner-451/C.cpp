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
    int q; cin >> q;
   
    int trees = 0;
    map<ll, ll> mp; 
    while(q--) {
        int t; cin >> t;
        ll h; cin >> h;
        
        if (t == 1) {trees++; cout << trees << "\n"; mp[h]++;}
        if (t == 2) {
            if (trees == 0) cout << 0 << "\n";
            else {
                ll sizeb = 0;
               
                auto it = mp.upper_bound(h);
                for (auto itr = mp.begin(); itr != it; ++itr) {
                    sizeb += itr->second;
                }

                mp.erase(mp.begin(), it);
                trees -= sizeb;

                cout << trees << "\n";
            }
        }
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
