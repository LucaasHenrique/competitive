#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (ll i = 1; i <= n; i++)
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

    vector<ll> a(n+1);
    forn (i, n) cin >> a[i];
    
    map<ll, int> s;
    int l = 1;

    int max_seq = 0;
    for (int i = 1; i <= n; i++) {
        if (s.find(a[i]) == s.end()) {
            s[a[i]] = i;
        } else{
            if (s[a[i]] >= l && s[a[i]] <= i) 
                l = s[a[i]] + 1;
           
            s[a[i]] = i;
        }

        max_seq = max(max_seq, (i - l) + 1);
    }

    cout << max_seq << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
