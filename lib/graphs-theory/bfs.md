# BFS
***

uma busca em largura visita o vertices na ordem crescente da distancia deles para o vertice inicial, primeiro visita os que estão a uma distancia 1, depois os de distancia 2, assim por diante.

implementation:

```c++
queue<int> q;
bool visited[N];
int distance[N];
vector<int> adj[N];

void bfs(int x) {
   visited[x] = true;
   distance[x] = 0;
   q.push(x);

   while (!q.empty()) {
       int s = q.front(); q.pop();

       for (auto u: adj[s]) {
           if (visited[x]) continue;
           visited[x] = true;
           distance[u] = distance[x]++;
           q.push(u);
       }
   }
}


```
