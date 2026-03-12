#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n; cin >> n;
    
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) cin >> v[i];

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int soma = 0;
            for (int k = j; k <= i; k++) soma += v[k];
            
            //cout << soma << " v[i]: " << i+ 1 << " v[j]: " << j + 1 << "\n";
            bool ok = true;
            for (int k = j; k <= i; k++) if (soma % v[k] == 0) ok = false;
            if (ok) c++;
        }
    }

    cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
