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

    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        if (x >= 15 && x < 20) {
            tot++;
        } else if (x == 20) {
            tot += 2;
        } 
    }

    cout << (tot >= n ? "O BRUTO FOI DERROTADO" : "O BRUTO ESTA VIVO TPK PARA O GRUPO") << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
