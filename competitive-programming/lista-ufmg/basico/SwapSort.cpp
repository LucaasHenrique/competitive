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

    int n; cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> p;
    int c =0;
    for (int i = 0; i < n; i++) {
        int m = i; 
        for (int t = i;  t < n; t++) {
           if (a[m] < a[i]) {
               m = t;
           } 
        }

        if (i != m) {
            swap(a[m], a[i]); c++;
            p.pb({i, m});
        }
    }

    cout << p.size() << "\n";
    for (auto [j, k]: p) {
        cout << j << " " << k << '\n';
    }
}

// 5 2 5 1 4
//

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
