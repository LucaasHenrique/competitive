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
        int n; cin >> n;
        int y, r; cin >> y >> r;
    
        int tot = 0;
        if (y == 0 && r == 0) {cout << 0 << "\n"; continue;}
        
        if (r <= n) {
            n -= r;
            tot += r;
            r = 0;
        }

        while (y > 1 && n > 0) {
            y -= 2;
            n -= 1;
            tot++;
        }

        cout << tot << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
