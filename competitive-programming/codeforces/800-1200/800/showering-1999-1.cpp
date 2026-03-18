#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int> 
#define pll pair<ll, ll> 
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n, s, m; cin >> n >> s >> m;

    vector<pii> a;
    bool t = false;
    
    int ini = 0;
    for (int i = 0; i < n; i++) {
        int l; int r; cin >> l >> r;

        int diff = abs(l - ini);
        if (diff >= s) {t = true; break;}
        ini = r;
    }

    if (m - ini >= s) t = true;

    cout << (t ? "YES" : "NO") << '\n';
}
int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
