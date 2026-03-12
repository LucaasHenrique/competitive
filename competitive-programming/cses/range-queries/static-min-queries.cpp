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

int a[maxn];
int seg[4*maxn];

int build(int p, int l, int r) {
    if (l == r) return seg[p] = a[l];
    int m = (l+r)/2;

    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r) {
    if (b < l or r < a) return INF32;
    if (a <= l and r <= b) return seg[p];
    
    int m = (l + r) / 2;
    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

void solve() {
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << query(a, b, 1, 0, n-1) << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
