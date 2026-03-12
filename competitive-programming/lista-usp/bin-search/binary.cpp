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

int binary_search(vector<int>& a, int t) {
    int l = 0, r = a.size() - 1;

    while (l < r) {
        int meio = (l + r) / 2;

        if (a[meio] == t) return meio;
        else if (a[meio] < t) l = meio + 1;
        else r = meio - 1;
    }

    return -1;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        int query; cin >> query;

        int m = binary_search(a, query);       
        if (m != -1) cout << m << "\n";
        else cout << -1 << "\n";
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
