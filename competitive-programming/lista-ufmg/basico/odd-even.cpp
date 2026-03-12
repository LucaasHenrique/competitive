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
    int a, b; cin >> a >> b;
    if (a == b) {cout << 0 << '\n'; return;}

    int diff = b - a;

    if (diff % 2 == 0 && diff > 0) {
        cout << 2 << '\n';
    } else if (diff % 2 != 0 && diff > 0) cout << 1 << "\n";
    
    if (diff < 0 && diff % 2 == 0) cout << 1 << '\n';
    else if (diff < 0 && diff % 2 != 0) cout << 2 << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
