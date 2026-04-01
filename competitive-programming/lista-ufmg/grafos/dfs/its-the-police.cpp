#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define forn(i, n) for (int i = 1; i <= n; i++)
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
#define MAXN 1000000

vector<int> g[MAXN];
vector<int> mp(MAXN, 0);
vector<int> vis(MAXN, 0);

void solve() {
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);
        mp[a]++; mp[b]++;
    }

    int min_g = INF32;
    int index = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i] < min_g) {
            min_g = mp[i];
            index = i;
        }
    }

    vis[index] = 1;
    for (auto u: g[index]) vis[u] = 1;
    
    
    for (int i = 1; i <= n; i++){
        if (vis[i]) cout << "0 ";
        else cout << "1 ";
    }
}

// obs: grau de vertice = quantidade de arestas que esse vertice possui.
// basicamente eu conto o grau de cada vertice, depois pego o vertice que possui o menor grau possivel e marco ele e todos os seus vizinhos como zero.
// pq? o problema quer que o yuriy deixe o maior numero de praças com policiamento o possivel para que não seja suspeito, cada vizinho de uma praça que é vigiada tbm é vigiado, ou seja,
// o vertice que quero deixar sem policiamento, não deve ter nenhum vizinho com policiamento.
// logo, se eu marcar o vertice que possui o maior numero de vizinhos eu não sou suspeitoo.

int32_t main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
