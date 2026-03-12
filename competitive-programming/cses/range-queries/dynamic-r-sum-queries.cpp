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

ll v[MAXN];
ll seg[4*MAXN];

ll build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];

    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

ll query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;

    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

ll update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l + r) / 2;

    return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
}

void solve() {
    
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);

    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            int k, u; cin >> k >> u;
            k--; 
            update(k, u, 1, 0, n-1);
        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            cout << query(a, b, 1, 0, n-1) << "\n";
        }
    }
}


int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
