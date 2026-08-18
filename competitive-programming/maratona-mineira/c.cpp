#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (ll i = 1; i <= n; i++)
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
    vector<int> a(n+1);
    forn (i, n) cin >> a[i];
    
    set<int> s;
    int idx = 0;
    int max = 0;
    forn (i, n) {
        //cout << max << " " << idx << "\n";
        if (!s.count(a[i])) {
            if (a[i] > max) {
                max = a[i];
                idx = i;
            }
            cout << max << " " << idx << "\n";
        }else {
            if (max == a[i]) idx = i;
            s.clear();
            cout << max << " " << idx << "\n";
            max = 0;
            idx = i;
            s.insert(a[i]);
            continue;
        } 

        
        s.insert(a[i]);
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
