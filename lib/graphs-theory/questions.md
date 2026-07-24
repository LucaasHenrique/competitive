# Questions
***

```txt
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is x, its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
```

solution: 

1. Rodar um dijkstra de 1 ate N; 
2. Rodar um dijkstra de N ate 1;
3. Computar o valor testando o descontro em cada aresta

```c++
void dijkstra(int source, vector<ll>& dist, vector<pair<ll, ll>> g[]) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    vector<bool> processed;    
    dist.assign(n + 1, INF);
    processed.assign(n + 1, false);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        pq.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : g[a]) {
            ll b = u.first;
            ll w = u.second;

            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                pq.push({dist[b], b});
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    vector<tuple<int, int, ll>> edges;
    
    forn (i, m) {
        int a, b; 
        ll w;
        cin >> a >> b >> w;
        g[a].pb({b, w});
        rev[b].pb({a, w});
        edges.pb({a, b, w});
    }

    vector<pii> path;
    vector<ll> dist;
    vector<ll> dist2;   
    
    dijkstra(1, dist, g);
    dijkstra(n, dist2, rev);
    
    ll ans = INF64;
    for (auto [u, v, w]: edges) {
        ans = min(ans, dist[u] + (w / 2) + dist2[v]);
    }

    cout << ans << "\n";
}
```

time complexity: O((V + E) log V)

question:

```txt
You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
Your task is to walk from room 1 to room n. What is the maximum score you can get?
```

solution: 

1. Colocar todos os pesos como negativos
2. Buscar o menor caminho com bellman ford, esse menor caminho vai ser o maior caminho do grafo não negado
3. Verificar se existe um ciclo positivo no grafo, se sim, isso permite que a pontuação aumente infinitamente.
4. Verificar se o ciclo positivo esta no caminho para chegar ate o vertice N, se sim a resposta é -1, se não e `dist[n]`;

```c++
const ll INF = ((ll)1 << 60);

int n, m; 
vector<tuple<int, int, ll>> g;
vector<ll> dist;
vector<int> rev[MAXN];
bool vis[MAXN];

void bellmanFord(int source) {
    dist.assign(n + 1, INF);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto e : g) {
            int a, b;
            ll w;
            tie(a, b, w) = e;

            if (dist[a] != INF)
                dist[b] = min(dist[b], dist[a] + w);
        }
    }
}

void dfs(int n) {
    vis[n] = true;

    for (auto u: rev[n]) {
        if (vis[u]) continue;
        dfs(u);
    }
}

void solve() {
    cin >> n >> m;
    forn (i, m) {
        int a, b; 
        cin >> a >> b;
        ll w; cin >> w;

        g.pb({a, b, -w,});
        rev[b].pb(a);
    }

    bellmanFord(1);
    
    bool cycle = false;
    dfs(n);
    for (auto e: g) {
        int a, b;
        ll w;
        tie(a, b, w) = e;

        if (dist[a] != INF && dist[a] + w < dist[b] && vis[b]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << -dist[n] << "\n";
}
```
***
question:

```txt
You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
```

solution:

1. Rodar um um bellman-ford para detectar um existencia de um ciclo negativo.
2. Guardar cada vertice do ciclo em um array

```c++
void bellmanFord() {
 
    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
 
            if (dist[a] != INF64 && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                parent[b] = a;
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    edges.resize(m);
    dist.resize(n + 1, 0);
    parent.resize(n + 1, -1);
    forn (i, m) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
 
    bellmanFord();
    ll cycle_start = -1;
    for (auto e : edges) {
        int a, b;
        ll w;
        tie(a, b, w) = e;
        if (dist[a] != INF64 && dist[b] > dist[a] + w) {
            dist[b] = dist[a] + w;
            parent[b] = a;
            cycle_start = b;
        }
    }
 
    if (cycle_start == -1) {
        cout << "NO\n";
        return;
    }
 
    for (int i = 0; i < n; i++) {
        cycle_start = parent[cycle_start];
    }
 
    vector<int> path;
    int cur = cycle_start;
    do {
        path.pb(cur);
        cur = parent[cur];
    } while (cur != cycle_start);
 
    path.pb(cycle_start);
    reverse(all(path));
 
    cout << "YES\n";
    for (auto e: path)
        cout << e << " ";
 
    cout << "\n";
```
