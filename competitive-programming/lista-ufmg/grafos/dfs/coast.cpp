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

void solve() {
    int m, n; cin >> n >> m;

    vector<vector<char>> mp(m, vector<char>(n+1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> mp[i][j];
    }

    int c = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == '#') {
                if ((i == 0 || j == 0 || i == m -1 ||  j == n - 1 || 
                            mp[i+1][j]=='.' || 
                            mp[i-1][j]=='.' || 
                            mp[i][j+1]=='.' || 
                            mp[i][j-1]=='.')) 
                        {
                        c++;
                }
            } 
        }   
    }


    cout << c << '\n';
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
