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
    
    while (n--) {
        int c = 0;
        int slices; cin >> slices;
        while (slices > 2) {
            int m1 = slices / 3;
            int m2 = (slices - m1) / 2;
            int m3 = slices - m1 - m2;
        
            slices = m3;
            c += m1;
        }
    
        cout << c << '\n';    
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
