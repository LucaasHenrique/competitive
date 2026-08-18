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
        
    string s; cin >> s;
    
    if (s[0] == s[s.size()-1]) cout << s << "\n";
    else {
        s[0] = s[s.size()-1];
        cout << s << "\n";
    }
}

//abbbabbba
// bbbaab
// abbb
// bbbbabababbab

// ab: 1 - 2 - 3 - 4 
// ba: 1 - 2 - 3 - 4
//
// ab: 1 - 2 - 3 - 4 - 5
// ba: 1 - 2 - 3 - 4 
int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
