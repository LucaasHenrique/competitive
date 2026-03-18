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

    if (a >= 5 && b >= 1) {
        cout << 0 << "\n";
        return;
    }

    if (b == 0) {
        if (a == 0) cout << 1;
        else if (a == 1) cout << 1;
        else if (a == 2) cout << 2;
        else if (a == 3) cout << 6;
        else cout << 0;
        return;
    }

    if (a == 0 || a == 1) cout << 1;
    else if (a == 2) cout << 6;
    else if (a == 3) cout << 6;
    else if (a == 4) cout << 6;

}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
