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

    unordered_set<int> log;
    
    string sub = "";
    for (int i = 0; i < s.size(); i++) {
        
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j] && log.count(s[j] == 0)) {
                log.insert(t[j]);
            } else if () 
        }
    }
    
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
