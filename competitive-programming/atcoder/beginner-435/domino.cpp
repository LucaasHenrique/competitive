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
    
    if (n == 0) {cout << 0; return;}
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    int c = 1 + v[1] - 1;
    int i = 2;
    while (i <= n) {
        if (i > c) break;
        int pos = i + v[i] - 1;

        if (pos < n) {
            c = max(c, pos);
        } else {
            c = min(n, pos);
            break;
        } 

        i++; 
    }

    cout << c;
}

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
