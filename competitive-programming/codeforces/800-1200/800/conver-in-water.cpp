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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    int pos = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {   
        if (s[i] == '.') cnt++;
        if (i > 0 && i < n - 1) {
            if (s[i-1] == '.' && s[i] == '.' && s[i + 1] == '.') {
                s[i] = 'W'; s[i-1] = 'W'; s[i+1] = 'W'; 
                cout << 2 << "\n";
                flag = false;
                break;
            }
        }
    }
    
    if (flag)cout << cnt << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
