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

ll ways(int k) {
    ll t_ways = ((long)k * k * (k * k - 1)) / 2;
    ll atack_ways = 4 * (k - 1) * (k - 2);

    return t_ways - atack_ways;

}

void solve() {
    
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << ways(i) << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    solve();
    return 0;
}
