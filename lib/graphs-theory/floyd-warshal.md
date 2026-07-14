# Floyd-Warshall Algorithm

encontra os menores caminhos entre todos os pares de vértices em uma única execução.

o algoritmo mantem uma matriz que contem as distancias entre os vertices. Inicialmente, distancias são calculas usando as arestas entre os vertices. Depois, o algoritmo reduz distancias usando vertices intermediarios.

exemplo: 

considere o grafo ponderado abaixo:

3 -7-> 4 -2-> 5

3 -2-> 2 -5-> 1 -1-> 5

4 -9-> 1

considere a matriz de distancias inicial:

  1 2 3 4 5
1 0 5 ∞ 9 1
2 5 0 2 ∞ ∞
3 ∞ 2 0 7 ∞
4 9 ∞ 7 0 2
5 1 ∞ ∞ 2 0

se usamos o vertice 1 como intermediario:

- podemos notar que agora existe um caminho entre o vertice 2 e 4 que passa por 1. Então podemos atualizar a distancia entre 2 e 4 para 14 (2 -> 1 -> 4):

- tambem vemos que existe um caminho entre 2 e 5 que passa por 1. Então podemos atualizar a distancia entre 2 e 5 para 6 (2 -> 1 -> 5):

  1 2 3 4 5
1 0 5 ∞ 9 1
2 5 0 2 14 6
3 ∞ 2 0 7 ∞
4 9 14 7 0 2
5 1 6 ∞ 2 0

fazemos isso sucessivamente colocando todos os vertices de 1 a N como intermediarios e atualizamos a matriz de distancias.

```c++
int n, m;
ll g[MAXN+2][MAXN+2];
ll dist[MAXN+2][MAXN+2];

void floyd_warshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (g[i][j] != INF64) dist[i][j] = g[i][j];
            else dist[i][j] = INF64;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF64 || dist[k][j] == INF64) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    int k; cin >> k;

    forn (i, n) {
        forn (j, n) {
            g[i][j] = INF64;
        }
    }

    forn (i, m) {
        int a, b;
        cin >> a >> b;
        ll w; cin >> w;
        g[a][b] = min(g[a][b], w);
        g[b][a] = min(g[b][a], w);
    }

    floyd_warshall();
    while (k--) {
        int a, b; cin >> a >> b;
        cout << (dist[a][b] == INF64 ? -1 : dist[a][b]) << "\n";
    }
}
```

the complexity is O(n^3).
