#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    n--;

    if (n == 0) {cout << 0; return;}
    if (n == 2) {
        cout << min(a, b) + min(b, c) << '\n';
        return;
    } 
    int aux = a;

    int sum = 0;
    for (int i = n; i > 0; i--) {
        if (aux == a) {
            aux = min(a, b);
        } else if (aux == b) {
            aux = c;
        } else {
            aux = min(b, c);
        }

        sum += aux;
    }

    cout << sum << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();
    return 0;
}
