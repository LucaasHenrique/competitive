#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int n, m, ans;
int arr[105];

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);*/
    
    cin >> n >> m;

    int it = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; 
        for (int j = 0; j < x; j++) arr[it+j] = y;
        it += x;
    }
    
    it = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        for (int j = 0; j < x; j++) ans = max(ans, y-arr[it+j]);
        it += x;
    }

    cout << ans;

    return 0;
}
