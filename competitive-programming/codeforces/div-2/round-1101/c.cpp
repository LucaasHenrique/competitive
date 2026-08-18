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
    
    int n, x, s; cin >> n >> x >> s;
    string f; cin >> f;
    
    string fs = ' ' + f;
    vector<int> a(x+1);
    for (int i = 1; i <= x; i++) a[i] = s;
    //for (auto p: a) cout << p << " ";
    
    int it = 0, am = 0, ex = 0; 
    for (int i = 1; i <= n; i++){
        if (a[i] == 'E') ex++;
        else if (a[i] == 'A') am++;
        else it++;
    } 
        
    int v = x, o = 0, l = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (fs[i] == 'E') {
                if (a[j] < s && a[j] > 0) {ans++; a[j]--; break;}
            } else if (fs[i] == 'I') {
                if (a[j] == s) {ans++; a[j]--; break;}
            } else if (fs[i] == 'A'){
                if (a[j] > 0) {ans++; a[j]--; break;}
            }
        }
    }

    cout << ans << "\n";
    

}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
