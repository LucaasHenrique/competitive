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
    
    ll a, b, c; cin >> a >> b >> c;

    bool ans = false;
    ll new_a = 2*b - c;
    if (new_a / a> 0 && new_a % a == 0) ans = true;

    ll new_b = (a + c) / 2;
    if (new_b / b > 0 && new_b % b == 0 && (c - a) % 2 == 0) ans = true;

    ll new_c = 2*b - a;
    if (new_c / c > 0 && new_c % c == 0) ans = true;

    cout << (ans ? "YES" : "NO") << "\n";
}

// 2b = a + c;

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
