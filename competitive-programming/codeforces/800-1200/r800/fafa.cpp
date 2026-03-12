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
    int a = n;
    for (int k = 1; k <= n; k++) {
        int p = a - k; 
        if (p % k == 0 && k != n) tot++;
    }
        
    cout << tot;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
