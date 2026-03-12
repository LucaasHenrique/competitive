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
#define f first
#define s second
#define pb push_back
#define MAXN 300100

void solve() {
    
    // x -> row, y -> column
    // quando x <= y temos q se y é impar achamos o valor com y² - (x-1), se não (y-1)² + x;
    // quando x > y temos q se x é par achamos o valor com x² - (y-1), se não (x-1)² + y;
    // x = 2 and y = 3; 3² - (2 - 1) = 8;
    // x = 4 and y = 2; 4² - (2 - 1) = 15;
    //

    ll x, y; cin >> x >> y;

    ll ans = 0;

    if (x <= y) {
        if (y % 2 == 0) ans = ((y - 1) * (y - 1)) + x;
        else ans = (y * y) - (x-1);
    } else {
        if (x % 2 == 0) ans = (x * x) - (y - 1);
        else ans = ((x - 1) * (x - 1)) + y;
    }

    cout << ans << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
    return 0;
}
