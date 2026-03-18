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

int rightmost_max(vector<int> a) {
    int max = 0, pos_max = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= max) {max = a[i]; pos_max = i;}
    }

    return pos_max;
}

void solve() {
    
    int n; cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    int c = 0;
    while (n > 0) {
        int pos = rightmost_max(a);
        cout << n << "\n";
        a.erase(a.begin() + pos, a.end());
        n -= pos;
        n++;
        c++; 
    }
    
    cout << c << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
