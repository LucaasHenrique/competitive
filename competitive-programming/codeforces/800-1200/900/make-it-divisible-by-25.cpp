#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (ll i = 0; i < n; i++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100

int p(string n, string s) {
    int c = 0;
    int check = s.size() - 1;
    int op = 0;

    for (int i = n.size() - 1; i >= 0; i--) {
        if (n[i] == s[check]) {
            check--;
            if (check < 0) break;
        } else op++;
    }
   
    if (check >= 0) op = INF32;

    return op;
}

void solve() {
    string n; cin >> n;

    vector<string> possible = {"00", "25", "75", "50"}; 
    int ans = INF32;

    for (auto po: possible) ans = min(ans, p(n, po));
    
    cout << ans << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
