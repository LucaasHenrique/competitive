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
    int n, m; cin >> n >> m;
    
    vector<int> a(n+1);
    vector<int> pos(n+5);
    forn(i, n) {cin >> a[i]; pos[a[i]] = i;}
        
    int r = 1;
    for (int i = 2; i <= n; i++) {
        r += (pos[i] < pos[i - 1]);
    }

    while (m--) {
        int i, j; cin >> i >> j;
        
        if (i > j) swap(i, j);

        int x = a[i];
        int y = a[j];
            
        if (pos[x + 1] > i && pos[x + 1] < j) r++;
        if (pos[x - 1] > i && pos[x - 1] < j) r--;
        if (pos[y + 1] > i && pos[y + 1] < j) r--;
        if (pos[y - 1] > i && pos[y - 1] < j) r++;
        
        if (x == (y-1)) r++;
        if (x == (y+1)) r--;
        
        cout << r << "\n";

        swap(a[i], a[j]);
        pos[x] = j;
        pos[y] = i;
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
