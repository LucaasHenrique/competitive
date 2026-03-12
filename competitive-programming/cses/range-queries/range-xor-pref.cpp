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

int v[MAXN];
int pref[MAXN];

void solve() {
    int q, n; cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> v[i];
    pref[0] = v[0];
    for (int i = 0; i <= n; i++) pref[i] = pref[i - 1] ^ v[i];

    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << (pref[a-1] ^ pref[b]) << '\n';
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
