# BFS Multi-Source

an example of bfs with multiple sources

```txt
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.
```

```c++
vector<string> g;

// r, d, u, l
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int direc[MAXN][MAXN];
int n, m; 
queue<pii> q;
vector<vector<int>> dist_m, dist_p;
ll closet_dist = INF64, closet_r =-1, closet_c = -1;

void bfs(vector<vector<int>>& dist) {
    while (!q.empty()) {
        int x = q.front().f, y = q.front().s;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                direc[nx][ny] = i;      
                q.push({nx, ny});
            }
        }
    }
}

void check(int x, int y) {
    if (g[x][y] != '#' && dist_p[x][y] < dist_m[x][y] && dist_p[x][y] < closet_dist) {
        closet_dist = dist_p[x][y];
        closet_r = x;
        closet_c = y;
    }
}

void solve() {
    
    cin >> n >> m;
    g.resize(n);
    forn (i, n) {
        cin >> g[i];
    }
    
    dist_m.resize(n, vector<int>(m, INF32));
    dist_p.resize(n, vector<int>(m, INF32));
     
    int x = 0, y= 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                x = i; y = j;
                dist_p[i][j] = 0;
            }  
            else if (g[i][j] == 'M') {
                dist_m[i][j] = 0;
                q.push({i, j});
            } 
        }
    }

    bfs(dist_m);

    q.push({x, y});
    bfs(dist_p);

    for (int i = 0; i < n; i++) {
        check(i, 0);
        check(i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        check(0, j);
        check(n - 1, j);
    }

    if (closet_dist == INF64) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        
        string res = "", dir = "RDUL";
        while (closet_r != x || closet_c != y) {
            int idx = direc[closet_r][closet_c];
            res += dir[idx];
            closet_r -= dx[idx];
            closet_c -= dy[idx];
        }

        reverse(res.begin(), res.end());
        cout << res.size() << "\n" << res << "\n";

    }
}
```
