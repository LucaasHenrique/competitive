// segment tree min;
#include <bits/stdc++.h>

using namespace std;
#define MAXN 300000
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
int v[MAXN];
int seg[4*MAXN];

int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];

    int m = (l+r)/2;
    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return INF32;
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;

    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l + r) / 2;

    return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

int main() {
    int n = 8;
    int i = 2, x = 1, a = 4, b = 6;
    build(1, 0, n - 1);

    cout << query(a, b, 1, 0, n-1);
    update(i, x, 1, 0, n-1);
}
