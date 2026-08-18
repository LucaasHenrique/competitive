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
    
    int n; cin >> n;    
    vector<ll> a(n);

    forn (i, n) cin >> a[i];
    
    sort(a.begin(), a.end()); 
    int b = a[n/2];
    
    int i = 0, j = n-1;
    int cnt = 0;
    while (i <= n / 2 && j >= n / 2) {
        if (a[i] == b && a[j] == b){ i++; j--; continue;}
        else {
            a[i] = b;
            a[j] = b;
            i++; j--;
            cnt++;
        }
    }

    cout << cnt << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
