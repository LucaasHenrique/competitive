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

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

void solve() {
    
    int a, b, xk, yk, xq, yq;

    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;
    int ans = 0; 
    set<pair<int, int>> s1, s2;
    for (int i = 0; i < 4; i++) {
        s1.insert({xk+dx[i]*a, yk+dy[i]*b});
        s2.insert({xq+dx[i]*a, yq+dy[i]*b});
        s1.insert({xk+dx[i]*b, yk+dy[i]*a});
        s2.insert({xq+dx[i]*b, yq+dy[i]*a});
    }

    for (auto x: s1) if (s2.find(x) != s2.end()) ans++;
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
