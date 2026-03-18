#include <bits/stdc++.h>
 
using namespace std;
 
#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
 
void solve() {
 
    int n, k; cin >> n >> k;
 
    int cont = 0;
    int sobra = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
 
        if (n == 1 && a > 8) {
            cout << -1;
            return;
        }

        if (a + sobra >= 8) {
            k -= 8;
            sobra += a - 8;
        } else {
            k -= a + sobra;
            sobra= 0;
        }
        
        cont++;

        if (k <= 0) {
            cout << cont << "\n"; 
            return;
        }
    }

    if (k > 0) {
        cout << -1;
        return;
    }
}
 
int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
