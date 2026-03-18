#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {

    int n = 6;
    vector<int> v(n);
    int soma = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
        soma += v[i];
    }
    
    if (soma % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    int media = soma / 2;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (v[i] + v[j] + v[k] == media) {
                    cout << "YES" << "\n";
                    return;
                }
                //cout << v[i] + v[j] + v[k] << "\n"; 
            }
        }
    }

    cout << "NO";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
