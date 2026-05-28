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

// a = 7, b = 5 => a <= 2 * b - true, b <= 2 * a -> true;
// 5, 4;
// 3 3;
// 2, 1
// 0 0

// l = remover 2 da esquerda e 1 da direita
// r = remover 1 da esquerda e 2 da direita
//
// seja x a quantidade de vezes q fizemos o movimento l
// seja y a quantidade de vezes q fizemos o movimento r 
// temos que:
// 2x + y = a
// x + 2y = b
//
//

void solve() {
    
    ll a, b; cin >> a >> b;
    if ((a + b) % 3 == 0 && a <= 2 * b && b <= a * 2) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
