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

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    bool is_dsc = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i+1]) {
            is_dsc = true;
            break;
        }
    }

    if (!is_dsc) {cout << "YES" << "\n"; return;}
   
    if (k < 2) {cout << "NO" << "\n"; return;}
    while (is_dsc && k > 1) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i+1]) {
                is_dsc = true;
                break;
            } else is_dsc = false;
        }
    } 
    
    cout << "YES" << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
