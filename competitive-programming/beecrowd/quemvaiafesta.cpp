#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define maxn 5050

int n;
string cn;
vector<int> graph[maxn];
bool visited[maxn];
int res = 0;

int dfs(int x) {
    visited[x] = true;
    res++;
    for (int v: graph[x]) {
        if (!visited[v]) {
            dfs(v);
        } 
    }

    return res;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> n;
        
        if (n == 0) break;
        for (int i = 1; i <= 1000; i++) visited[i] = false;

        for (int i = 1; i <= n; i++) {
            cin >> cn;
            int a, b;
            sscanf(cn.c_str(), "(%d, %d)", &a, &b); 

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        

        cout << dfs(1) << '\n';

        for (int i = 0; i < maxn; i++) {
            graph[i].clear();
        }
        
        for (int i = 0; i < maxn; i++) {
            visited[i] = false;
        }
 
        res = 0;
    } 
     
    return 0;
}
