#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    string s; cin >> s;
    int n; cin >> n;

    bool left = false, right = false;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;

        if (t == s) {
            cout << "YES";
            return;
        }

        if (t[1] == s[0]) left = true;
        if (t[0] == s[1]) right = true;
    }

    cout << ((left && right) ? "YES" : "NO");


}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
