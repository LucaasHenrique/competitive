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

    vector<int> e(n + 1);
    for (int i = 1; i <= n; i++) cin >> e[i];

    for (int i = 1; i <= n; i++) {
        int a = e[i];
        int b = e[a];
        int c = e[b];
        
        if (c == i) {
            if (i != a && a != b && b != i) {
                cout << "YES";
                return;
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
