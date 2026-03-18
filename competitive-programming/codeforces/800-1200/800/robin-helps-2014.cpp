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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    
    int c = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            c += a[i];
        }
        if (a[i] == 0 && c >= 1) {
            c--;
            t++;
        }

    }

    cout << t << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
