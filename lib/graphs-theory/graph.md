# Graphs
***

Um grafo é uma estrutura matematica que pode ser definida com um conjunte de vertices e arestas:

G = (V, E);

### Caminho 

Um caminho em grafos é uma sequencia de arestas, em que cada aresta ligam dois vertices consequitivos, começando no vertice A e terminam no vertice B

exemple: A -> B -> C -> D;

um caminho é dito simples se cada vertice aparece somente uma vez;

`Ciclo`:

Um caminho é ciclo se ao pecorrer esse caminho eu volto para o vertice inicial:

example: A -> B -> C -> A;

além disso, um caminho pode conter um ciclo:

example: A -> B -> C -> A -> D;
***

### Conectividade

Um grafo é dito conexo se existe um caminho para todos os vertice, ou seja, posso sair de um vertice e chegar em qualquer outro vertice.

Todas as partes conexas de um grafo são chamadas de componentes.
***

### Tree

Uma Tree é um grafo conexo que não contem ciclos, consiste de n vertices e `n - 1` arestas.
***

### Edge Directions

Um grafo é dito direcionado se uma aresta pode ser percorrida em somente uma direção.

example: A -> B -> C -> D.

não existe uma caminho de D para A.
***

### Edge Weights

Um grafo é dito ponderado se suas arestas possuem um peso, esse "peso" pode ser interpretrado como o tamanho dessa arestas (muito usado em algoritmos de menor caminho). 

O tamanho de caminho (A, B) em grafos ponderados vai ser a soma de todos os pesos de cada aresta que sai de A ate B.
***

### Neighbors and degree

Dois vertices são vizinhos se existe um arestas entre eles dois.

O grau de um vertice é o numero de vizinhos que ele possui.

a soma do grau de um vertice é sempre 2*m, onde m é o numero de arestas.

um grafo é regular se o grau de cada vertice é uma constante `d`.

um grafo é completo se o grau de cada vertice é `n - 1`, nesse caso todo vertice esta ligado diretamento a todo os outros.

exemplo: A -> B, A -> C 
         B -> A, B -> C 
         C -> A, C -> A 

todo grafo completo é regular, mas nem todo grafo regular é completo.

o grau de saida de um vertice é o numero de arestas que começam nele.
o grau de entrada de um vertice é o numero de arestas que terminam nele.
***

### Colorings

em uma coloring de um grafo, cada vertice é pintado com uma cor de modo que dois vertices adjacente nao tenha a mesma cor.

Um grafo é bipartido se é possivel é colorir usando apenas duas cores.

exemplo de verificação se grafo pode ser bipartido ou não.
```c++
vector<int> g[MAXN];
bool possible, vis[MAXN];

void dfs(int x, vector<bool>& t, int p = 0) {
    vis[x] = true;
    
    for (auto u: g[x]) {
        if (u != p) {
            if (vis[u]) {
                if (t[u] == t[x]) possible = false;
            } else {
                t[u] = !t[x];
                dfs(u, t, x);
            }
        }
    }
}

void solve() {
    
    int n, m; cin >> n >> m;
    forn (i, m) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    vector<bool> team(n+1, 1);
    possible = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, team);
        }
    }
    if (!possible) {cout << "IMPOSSIBLE" << "\n"; return;}
    for (int i = 1; i <= n; i++) cout << (team[i] ? 1 : 2) << " "; 
    cout << "\n";
}
```

***
### Representação 

- Lista de adjacencia:

```c++
vector<int> adj[N];

adj[1].push_back(2);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);
```

Se o grafo for ponderado fazemos:

```c++
vector<pair<int,int>> adj[N];
```
***
