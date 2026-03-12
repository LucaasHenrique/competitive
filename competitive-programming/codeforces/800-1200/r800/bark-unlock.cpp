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
    
    string ss = "";
    /*vector<pair<char, char>> p; 

    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        if (n == 1 && t == s) {
            cout << "YES";
            return;
        }

        if (t == s) {
            cout << "YES";
            return;
        }
        if (t[0] == s[0] || t[0] == s[1] || t[1] == s[0] || t[1] == s[1]) p.push_back({t[0], t[1]});
    }

    bool m = true;
    for (int i = 0; i < p.size(); i++) {
        if (p[i].second == s[0] && m) {
            ss += p[i].second;
            m = false;
            i = 0;
        }

        if (p[i].first == s[1] && !m) {
            ss += p[i].first;
            break;
        }
    }

    cout << (ss == s ? "YES" : "NO");*/
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
