// new world, new me, new array;

#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    
    int t; cin >> t;
    while (t--) {
        int n, k, p; cin >> n >> k >> p;
        vector<int> a(n + 1, 0);    
        int c = 0;

        if (k < 0) {
            k = k * (-1);
        } 
        
        c = k / p; 
        if ((k % p) != 0) {
            c++;
        }
        
        if (n < c) {
            cout << -1 << '\n';
        } else cout << c << "\n";
    }

}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
