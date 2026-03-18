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
        ll a, b; cin >> a >> b; 

        if (a % b == 0) {cout << 0 << '\n';}
        else {
            cout << b - (a % b) << "\n"; 
        }
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
