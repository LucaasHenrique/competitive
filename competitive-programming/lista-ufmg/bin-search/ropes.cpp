#include <bits/stdc++.h>
#include <iomanip>

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

int n;int k; 
vector<double> a;

bool okk(double r) {
   
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] / r; 
    }

    return cnt >= k;
}

void solve() {
    
    cin >> n >> k;
    a.resize(n);
    double l = 0, r = 1e9;
    for (int i = 0; i < n; i++) {cin >> a[i];}
        
    int p = 200;
    double ans = 0;
    while (p--) {
        double m = l + (r - l) / 2;
        if (okk(m))  {
            l = m; 
        } else r = m;
    }

    cout << setprecision(7)<< l << '\n';
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
