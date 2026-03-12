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
#define sec second
#define pb push_back
#define MAXN 300100

void solve() {
    int n, t; cin >> n >> t;
    string s; cin >> s;

    while (t--) {
        vector<pair<int, int>> pos;
        for (int i = s.size()-1; i > 0; i--) {
            if (s[i] == 'G' && s[i-1] == 'B') {
                pos.pb({i, i-1}); 
            } 
        }

        for (auto [x, y]: pos) {
            swap(s[x], s[y]);
        }
    }
    cout << s << '\n';
}

// BBGBBG
// BGBBGB
// GBBGBB

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
