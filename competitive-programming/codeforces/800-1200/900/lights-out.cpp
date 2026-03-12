#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100

void altera(int n, int i, int j, vector<vector<int>>& r_mat) {
    if (i + 1 < n) r_mat[i+1][j] = !r_mat[i+1][j]; 
    if(i - 1 >= 0) r_mat[i-1][j] = !r_mat[i-1][j];
    if(j + 1 < n) r_mat[i][j+1] = !r_mat[i][j+1];
    if(j - 1 >= 0) r_mat[i][j-1] = !r_mat[i][j-1];
}

void solve() {
    int n = 3;
    
    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> r_mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) r_mat[i][j] = 1;}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (mat[i][j] % 2 != 0){r_mat[i][j] = !r_mat[i][j]; altera(n, i, j, r_mat);}
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << r_mat[i][j];
        cout << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

// 0 0 1
// 0 1 0
// 1 0 0

// 0 0 1
// 0 0 0
// 0 0 1
