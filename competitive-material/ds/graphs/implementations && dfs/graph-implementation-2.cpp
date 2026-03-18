#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue
#define maxn 5050

int n = 5;
vector<int> graph[maxn];
map<int, bool> visitado;
int target = 4;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visitado[x] = true;

    int c = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();

        //cout << u << " ";

        for (int v: graph[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                q.push(v);
                c++;
            }

            if (v == target) break;
        }
    }

    cout << c << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    return 0;
}
