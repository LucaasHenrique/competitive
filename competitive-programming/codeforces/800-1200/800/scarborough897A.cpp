#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        char c1, c2; cin >> c1 >> c2;

        l = l - 1;
        r = r - 1;

        for (l; l <= r; l++) {
            if (s[l] == c1) {
               s[l] = c2;
            }
        }
    }

    cout << s << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
