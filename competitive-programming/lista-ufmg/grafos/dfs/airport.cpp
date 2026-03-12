#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100
void solve() {
    int c = 0;
    while (true) {
        c++;
        int A, V; cin >> A >> V;
        if (A == 0 && V == 0) break;
        vector<int> g(101, 0);
        for (int i = 0; i < V; i++) {
            int a, b; cin >> a >> b;

            g[a]++;
            g[b]++;
        }

        int m = *max_element(g.begin(), g.end());
        
        cout << "Teste " <<  c << '\n';
       
        for (int i = 0; i < g.size(); i++) {
            if (g[i] >= m) cout << i << " ";
        }
    
        cout << '\n';
    }     
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
