#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    ll n, m; cin >> n >> m;

    map<pair<ll, ll>, ll> mp; 
    
    int t = 0;
    for (int i = 0; i < m; i++) {
        ll r, c; cin >> r >> c;
        
        r = r - 1;
        c = c - 1;
        if (r + 1 < n && c + 1 < n) {
            if (mp[{r, c}] == 0 && mp[{r+1, c}] == 0 && mp[{r, c+1}] == 0 && mp[{r+1, c+1}] == 0) {
                mp[{r, c}] = 1;
                mp[{r+1, c}] = 1;
                mp[{r, c+1}] = 1;
                mp[{r+1, c+1}] = 1;

                t += 1;
            }
        }   
    }

    cout << t; 
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
