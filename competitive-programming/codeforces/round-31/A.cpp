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
        
        int l, a, b; cin >> l >> a >> b;
        
        int maxe = a;
        int init_a = a;
        while ((a + b) % l != init_a) {
            a = (a + b) % l;
            
            maxe = max(maxe, a);
        }

        cout << maxe << "\n";
    }
        
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
