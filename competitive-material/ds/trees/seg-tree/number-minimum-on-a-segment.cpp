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
#define maxn 300100

int v[maxn];
pair<int, int> seg[4*maxn];
pair<int, int> combina(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return {a.first, b.second};
}

pair<int,int> build(int p, int l, int r) {
    if (l == r) return seg[p] = {v[l], 1};
    int m = (l+r) /2;

    seg[p] = combina(build(2*p l, m), build(2*p+1, m+1, r));
}

pair<int, int> query(int a, int b int p, int l, int r) {
    if (b < l or a < r) return {INF, -1};
    if (a <= l && r <= b) return seg[p];

    int m = (l+r)/2;
    return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

pair<int, int> update(int i, int x, int p, int l, int r) {
    if (i < l or r < x) return seg[p];
    if (l == r) return seg[p] = {x, 1};
    return seg[p] = combina(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

void solve() {
    
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> v[i];
    
    while(q--) {
        int t; cin >> t;
        if (t == 1) {// update 
            int i, x; cin >> i >> x;
            update(i, x, 1, 0, n-1);
        }else {
            int l, r; cin >> l >> r;
            auto [x, y] = query(l, r, 1, 0, n+1);
        }
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
