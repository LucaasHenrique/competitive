# Dijkstra's Algorithm
***

Dijkstra encontra o menor caminho de um vertice inicial para todos os outros vertices em um grafo.

Porem é mais eficiente que Bellman-Ford e pode processar grafos gigantes.

Mas os pesos no grafo devem ser não negativos.

assim como o bellman-ford, o disjkstra mantem a distancia para os vertices e reduz em cada pesquisa.

Processa cada vertice somente uma vez, partindo do fato de que não existe arestas negativas.
***

Inicialmente, a distância para todos os vértices é definida como infinito, exceto para o vértice de origem, cuja distância é 0.

Em cada iteração, o algoritmo seleciona o vértice não processado com a menor distância conhecida.

Em seguida, realiza o relaxamento das arestas adjacentes, atualizando a distância dos vértices vizinhos sempre que encontrar um caminho menor.

O vértice é marcado como processado e o processo se repete até que todos os vértices alcançáveis sejam processados.

# Implmentation

```c++
#define MAXN 100005
const int INF = 1e9;

int n, m;
vector<pair<int, int>> g[MAXN];
vector<int> distance;
vector<bool> processed;

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    distance.assign(n + 1, INF);
    processed.assign(n + 1, false);

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int a = pq.top().second;
        pq.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : g[a]) {
            int b = u.first;
            int w = u.second;

            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                pq.push({distance[b], b});
            }
        }
    }
}

void solve() {
   cin >> n >> m;
  
   forn (i, m) {
       int a, b, w;
       cin >> a >> b >> w;
       g[a].push_back({b, w});
       g[b].push_back({a, w});
   }

   int source; cin >> source;

   dijkstra(source);

   for (int i = 1; i <= n; i++) {
       if (distance[i] == INF)
           cout << "Distance to " << i << ": INF\n";
       else
           cout << "Distance to " << i << ": " << distance[i] << '\n';
   }
}

```

the time complexity is O(n + m log m), cause the algorithm goes through all nodes of the graph and adds for each edge at most
one distance to the priority queue.
