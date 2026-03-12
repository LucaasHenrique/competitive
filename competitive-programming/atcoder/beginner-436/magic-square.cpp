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
    int mat[n][n] = {};

    int r = 0, c = (n-1)/2;
    int k = 1;
    
    mat[r][c] = k;

    for (int i = 0; i < (n*n) - 1; i++) {
        int rl = ((r - 1) + n) % n;
        int cl = (c + 1) % n;

        k++;
        if (mat[rl][cl] == 0) {r = rl; c = cl; mat[r][c] = k;}
        else {r = (r + 1) % n; mat[r][c] = k;} 

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
