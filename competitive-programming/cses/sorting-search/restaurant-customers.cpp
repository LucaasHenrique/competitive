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
 
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.s > b.s;
}
 
void solve() {
    
    ll n; cin >> n;
    vector<ll> arr, dep;
    while (n--) {
        ll a, b; cin >> a >> b;
            arr.pb(a); dep.pb(b);
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    ll max_c = 0, curr = 0;
    int p = arr.size();
    int i = 0, j = 0;

    while (i < p && j < p) {
        if (arr[i] < dep[j]) {
            curr++;
            max_c = max(max_c, curr);
            i++;
        } else {j++; curr--;}
    }

    
    cout << max_c << "\n";
}
 
int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
