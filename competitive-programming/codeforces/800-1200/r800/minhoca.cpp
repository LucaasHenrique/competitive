#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    
    int n, m; cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int aux = 0;
    int aux2 = 0;
    for (int i = 0; i < m; i++) {
        int soma = 0;
        for (int j = 0; j < n; j++) {
            soma += mat[j][i];
        }

        aux = max(aux, soma);
    }
    
    for (int i = 0; i < n; i++) {
        int soma = 0;
        for (int j = 0; j < m; j++) {
            soma += mat[i][j];
        }

        aux2 = max(aux2, soma);
    }

    cout << max(aux, aux2) << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
