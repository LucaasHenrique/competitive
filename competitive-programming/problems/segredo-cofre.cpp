#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define uset unordered_set
#define umap unordered_map 
#define pqueue priority_queu
#define MAXN 100100

int v[MAXN], f[MAXN];
long long dig[10];

void upd(int l, int r, int d) {
    f[l] += d;
    f[r + 1] -= d;
}

int main (int argc, char *argv[]) {
    
    int n, m; cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int last = 1;

    upd(1, 1, 1);

    for (int i = 1; i <= m; i++) {
        int next; cin >> next;

        int l = min(last, next), r = max(last, next);

        upd(l, r, 1);
        upd(last, last - 1);

        last = next;

    }
    
    for(int i=1;i<=n;i++){
        f[i] = f[i - 1];
        dig[v[i]] += f[i];
    }

    for (int y = 0; y < 10; y++) cout << dig[y] << "\n";
}
