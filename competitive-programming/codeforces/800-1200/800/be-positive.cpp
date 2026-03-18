#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int t;

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        int n; cin >> n;
        int op0 = 0, op = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 0) op0++;
            else if (x == -1) op++;
        }   

        if (op % 2 == 0) cout << op0 << "\n";
        else cout << op0 + 2 << "\n";
    }
        
    return 0;
}









