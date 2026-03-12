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
 
void solve() {
    int n, q; cin >> n >> q;
 
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    if (b[n-1] > a[n-1]) a[n-1] = b[n-1];
    for (int i = n-2; i >= 0; i--) {
        a[i] = max(b[i], a[i+1]);
    }
    
    int pref[n];
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        if (l == 0) cout << pref[r] << " ";
        else cout << pref[r] - pref[l-1] << " ";
    }
    cout << "\n";
}
 
int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t; while (t--) solve();
    return 0;
}

