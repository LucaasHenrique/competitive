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

ll bin_search(ll k, vector<ll>& a) {
    ll l = 0, fim = a.size() - 1;

    while (l <= fim) {
        ll m = (l + fim) / 2;

        if (a[m] == k) return m;
        else if (a[m] > k) fim = m - 1;
        else l = m + 1; 
    }

    return -1;
}

void solve() {
    
    ll n, k; cin >> n >> k;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    while (k--) {
        ll b; cin >> b;

        if (bin_search(b, a) != -1) cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
