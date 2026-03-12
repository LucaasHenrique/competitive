#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)


void solve() {
    int a, b;
    cin >> a >> b;

    if (b >= 3) {
        cout << 0 << "\n";
    } else if (b == 2) {
        if (a == 2) cout << 1 << "\n";
        else cout << 2 << "\n";
    } else {
        // b == 0 ou b == 1
        cout << 1 << "\n";
    }
}


int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
