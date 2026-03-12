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
#define s second
#define pb push_back
#define MAXN 300100

int bin_search(ll n, ll k) {
    ll l = 1, r = 1e18;

    while (l < r) {
        ll meio = (l + r) / 2;
        if (meio - (meio/n) >= k) r = meio;
        else l = meio + 1;
    }

    return l;
}

void solve() { 
    ll n, k; cin >> n >> k;
    cout << bin_search(n, k) << "\n"; 
}

// 1 2 3 5 6 7 9 10 11 13 14 15
//

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
