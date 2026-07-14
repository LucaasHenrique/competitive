# DFS
***

Busca em profundidade (dfs)

Esse algoritmo começa em um vertice é visita todos os vertices que são alcançaveis usando as arestas.

A pesquisa segue um caminho unico o maximo que ela conseguir, caso nao tenha mais vertices a serem visitados nesse caminho ela volta para o inicial e verifica se existe algum outro caminho nao percorrido


implementation:

```c++
vector<int> adj[N];
bool visited[N];

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = true;

    for (auto u: adj[n]) {
        dfs(u);
    }
}
```





