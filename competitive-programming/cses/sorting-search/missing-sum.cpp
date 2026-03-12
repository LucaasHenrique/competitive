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

int v[MAXN];
int seg[4*MAXN];

int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];

    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

int query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;

    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l + r) / 2;

    return seg[p] = update(i, x, 2*p, l m) + update(i, x, 2*p+1, m+1, r);
} 

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll sum = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > sum) {cout << sum << "\n"; exit(0);};

        sum += a[i];
    }

    cout << sum << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
