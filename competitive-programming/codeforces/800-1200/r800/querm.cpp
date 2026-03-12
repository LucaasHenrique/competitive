#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {

    int i = 0;
    while (true) {
        i++; 
        int n; cin >> n;

        if (n == 0) return;

        vector<int> a(n);
        int aux = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            if (a[i] - 1 == i) {
                aux = a[i];
                break;
            }
        }

        cout << "Teste " << i << '\n' << aux << '\n';
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
