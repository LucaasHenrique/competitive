# Direct Acyclic Graph
***

# Ordenação topologica 

-> ordena os vertices de um grafo DAG de forma que o vertice A tenha um caminho para o vertice B, e o vertice A aparece antes do vertice B.

1 -> 2 -> 3 -> 6 
^    ^       
|    |    
4 -> 5 -> 3  

4 -> 1 
4 -> 5 
1 -> 2 
5 -> 2 
2 -> 3
5 -> 3 
3 -> 6 

Algoritmo de Kahn

ideia:

1. calcular o indegree de cada vertice.
2. colocar na fila todos os vertices com indegree = 0.
3. retirar um vertice da fila e adiciona-lo a resposta. 
4. para cada vizinho dele, diminuir o indegree.
5. se algum vizinho chegar a indegree = 0, colocar na fila.
6. se no final não conseguimos colocar todos os vertices resposta, existe um ciclo.

complexida => O(V + E)

```c++ 
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int u = 0; u < n; u++) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() != n) {
        return {};
    }

    return topo;
}
```

Topological Sort com DFS

ideia: 

3 estados 

0 -> ainda não visitei esse vertice 
1 -> estou visitando agora 
2 -> terminei de visitar 

```c++  
vector<vector<int>> adj;
vector<int> state;
vector<int> topo;

bool dfs(int u) {
    state[u] = 1;

    for (int v : adj[u]) {

        if (state[v] == 1)
            return false; 

        if (state[v] == 0) {
            if (!dfs(v))
                return false;
        }
    }

    state[u] = 2;
    topo.push_back(u);

    return true;
}

bool topological_sort(int n) {
    state.assign(n, 0);
    topo.clear();

    for (int u = 0; u < n; u++) {
        if (state[u] == 0) {
            if (!dfs(u))
                return false;
        }
    }

    reverse(topo.begin(), topo.end());
    return true;
}
```

quantos caminhos existem ate o vertice x? 

```c++
    
vector<int> g[MAXN];
int dp[MAXN];

void solve() {
    int n, m;

    forn (i, m) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }

    dp[1] = 1;
    memset(dp, 0, sizeof dp);
    vector<int> topo = topSort(g);

    for (auto u: topo) {
        for (int v:: g[u]) {
            dp[v] += dp[u];
        }
    }
}

```

qual o maior caminho q chega no vertice x? 

```c++
vector<vector<int>> adj;
vector<int> state;
vector<int> topo;

bool dfs(int u) {
    state[u] = 1;

    for (int v : adj[u]) {

        if (state[v] == 1)
            return false; 

        if (state[v] == 0) {
            if (!dfs(v))
                return false;
        }
    }

    state[u] = 2;
    topo.push_back(u);

    return true;
}

bool topological_sort(int n) {
    state.assign(n+1, 0);
    topo.clear();

    for (int u = 1; u <= n; u++) {
        if (state[u] == 0) {
            if (!dfs(u))
                return false;
        }
    }

    reverse(topo.begin(), topo.end());
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    
    adj.assign(n + 1, vector<int>());
    forn (i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }
    
    topological_sort(n);

    vector<int> dp(n+1, 0);
    for (auto u: topo) {
        for (auto v: adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    cout << *max_element(all(dp)) << "\n";
}
```
