cycle
***

how we can find a cycle in undirected graph? 

the problem "round trip" in cses is about cycle detection on undirected graphs:

```
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
```

```c++
vector<int> g[MAXN];
bool vis[MAXN];
bool possible = false;
int parent[MAXN];
int s, e;
 
void dfs(int v, int p = 0) {
   vis[v] = true;
    
   if (possible) return;
 
   for (auto u: g[v]) {
        if (!vis[u]) {
            parent[u] = v;    
            dfs(u, v);
            if (possible) return;
        } else if (vis[u] && u != p) {
            s = u; 
            e = v;
            possible = true;
            return;
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
    
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]){
            dfs(i);
            if (possible) break;
        }
    }
    if (!possible) {cout << "IMPOSSIBLE" << "\n"; return;}
    
    vector<int> path;
    int c = e;
    while (c != s) {
        path.pb(c);
        c = parent[c];
    }
    
    path.pb(s);
    reverse(all(path)); 
    
    path.pb(s);
    cout << path.size() << "\n";
    for (auto p: path) cout << p << " ";
    cout << "\n";
}
```
