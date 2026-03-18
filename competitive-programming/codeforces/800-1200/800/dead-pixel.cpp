#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {

    int t; cin >> t;
    while (t--) {
        int a, b, x, y; cin >> a >> b >> x >> y;
    
        int l = b * x, abv = a * y, be = a * (b - 1 - y), r = b * (a - 1 - x);
        int ans = max({l, abv, be, r});

        cout << ans << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
