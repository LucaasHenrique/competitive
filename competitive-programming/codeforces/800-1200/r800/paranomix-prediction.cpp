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

bool isPrime(int y) {
    if (y <= 1) return false;
    
    for (int i = 2; i * i <= y; i++) {
        if (y % i == 0) return false;
    }

    return true;
}

void solve() {
    int n, m; cin >> n >> m; 

    int ans = 0;
    n++;
    for (int i = n; i < 50; i++) {
        if (isPrime(i)) {ans = i; break;} 
    }

    cout << (ans == m ? "YES" : "NO") <<'\n';
}

// 1 2 3 5 7 11 13

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
