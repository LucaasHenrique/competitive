#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    if (s.find(t) != string::npos) {cout << 0; return;}
    int c = 0; 
    for (int k = m; k < s.size(); k += m) {
        for (int i = 0; i < k; i++) {
        }

        if (s.find(t) != string::npos) {cout << c; return;}    
    }

    while (s.find(t) == string::npos) {

        for (int i = 0; i < m; i++) {

        }
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
