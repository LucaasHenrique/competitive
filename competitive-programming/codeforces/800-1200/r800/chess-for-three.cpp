#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {

    int n; cin >> n;

    int j1 = 1, j2 = 2, spec = 3;
    int possible = true;

    int ant = 0;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        if (a == 3 && i == 0) {cout << "NO"; return;}

        if (a == spec) possible = false;
        else {
            if (a == 1) spec = 6 - a - spec;
            if (a == 2) spec = 6 - a - spec;
            if (a == 3) spec = 6 - a - spec;
        }
    }

    cout << (possible ? "YES" : "NO");
}

int main (int argc, char *argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
