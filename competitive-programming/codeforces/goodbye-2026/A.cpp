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
        string s; cin >> s;

        for (int i = 0; i <= s.size() - 1 && s.size() >= 2; i++) {
            if (s[i] == 'N' && s[i + 1] == 'N') {
                s.erase(i, 1);
                i--;
            } else if ((s[i] == 'Y' && s[i+1] == 'N') || (s[i] == 'N' && s[i+1] == 'Y')) {
                if (s[i] == 'N') s.erase(i, 1);
                else if (s[i+1] == 'N') s.erase(i+1, 1);
                i--;
            }
        }
        
        cout << (s.size() > 1 ? "NO" : "YES") << "\n";
        
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
