#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    ll a, b; cin >> a >> b;
    
    int ans = 1;
    
    if (b - a >= 5) {
        cout << 0;
        return;
    } else {
        for (ll i = a + 1; i <= b; i++) {
            ans = (ans * (i%10))%10;
        }
    }

    cout << ans << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
