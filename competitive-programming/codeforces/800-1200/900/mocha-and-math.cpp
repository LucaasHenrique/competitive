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

//
// 11 7 15 3 7
// 3 7 15 3
// 3 7 15 3
// 3 7 7 3
// 3 3 3 3

// the bitwise AND never increases a value, this means theres a floor or minimum possible value that any element can become. What is this floor, and can all elements be made equal to it?

void solve() {
    int n; cin >> n;

    vector<ll> a(n); 
    forn (i, n) cin >> a[i];
    
    int mint = a[0];
    for (int i = 1; i < n; i++) {
        mint &= a[i]; 
    } 

    cout << mint << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
