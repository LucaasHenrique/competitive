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
    int x, n, m; cin >> x >> n >> m;
    
    while (x > 0 && n && x > (x/2) + 10) {
        x = (x / 2)+10;
        n--;
    }

    if (m*10 >= x) cout << "YES" << '\n';
    else cout << "NO" << "\n";

}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
