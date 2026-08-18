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
    
    ll n; cin >> n;
    vector<ll> a(n); 
    
    ll sum = 0;
    ll zeros = 0, ones = 0;
    forn (i, n) {
        cin >> a[i];}

    for (int i = 0; i < n; i ++) {
        if (a[i] == 0) zeros++;
        else if (a[i] == 1) ones++;
    }

    cout << (1LL << zeros) * ones << "\n";
     
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
