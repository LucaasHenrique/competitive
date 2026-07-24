# Bellman-Ford
***

Encontra o menor caminho de vertice inicial para todos os outros vertices do grafo. Pode processar todos os tipos de grafo, desde que o grafo nao contenha um ciclo de peso negativo. Se o grafo contem um ciciclo negativo, o algoritmo consegue detectar isso.

o algoritmo guarda a distancia do vertice atual para todos os outros vertices. Inicialmente, a distancia do para o vertice atual é 0 e para todos os outros vertices é infinito.

O algoritmo reduz a distancia encontrando arestas que reduzam o caminho atual ate que não seja mais possivel reduzir o caminho.

```c++

const int INF = 1e9;


vector<tuple<int, int, int>> edges;
vector<int> distance;

void bellmanFord(int n, int source) {
    for (int i = 1; i <= n; i++)
        distance[i] = INF;

    distance[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;

            if (distance[a] != INF)
                distance[b] = min(distance[b], distance[a] + w);
        }
    }
}

void solve() {
    
    int n, m; cin >> n >> m;

    forn (i, m) {
        int a, b, w; cin >> a >> b >> w;

        edges.pb({a, b, w});
    }

    // vertice de origem
    int x, cin >> x;

    for (int i = 1; i <= n; i++) {
        if (distance[i] == INF)
            cout << "Distancia ate " << i << ": INF\n";
        else
            cout << "Distancia ate " << i << ": " << distance[i] << "\n";
    }

    // to detect if the graphs contains a negative cycle
    bool hasNegativeCycle = false;
    
    for (auto e : edges) {
        int a, b, w;
        tie(a, b, w) = e;
    
        if (distance[a] != INF &&
            distance[a] + w < distance[b]) {
            hasNegativeCycle = true;
        }
    }
}
```

the complexity is O(n * m)

question: 

