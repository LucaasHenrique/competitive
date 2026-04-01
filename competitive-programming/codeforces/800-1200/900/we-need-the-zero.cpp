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

vector<int> xorize(int x, vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = a[i] ^ x;
    }

    return a;
}

void solve() {

    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    
    int x = 0;

    while (x <= 256) {
        
        vector<int> b = xorize(x, a);

        int sum =0; 
        for (int i = 0; i < n; i++) {
            sum ^= b[i];    
        }

        if (sum == 0) {cout << x << "\n"; return;}
        x++;
    }

    cout << -1<< '\n';
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
