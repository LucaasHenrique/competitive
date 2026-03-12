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
    map<string, int> mp;
    vector<string> o = {"Abigail", "Sebastian", "Penny", "Sam", "Leah", "Harvey", "Haley","Maru", "Alex", "Emily"};
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int m; cin >> m;
        
        mp[s] += m;
    }
    
    int tot = 0;

    for (auto &p: o) {
        while (mp[p] >= 250 && tot < 8) {
            mp[p] -= 250;
            tot++;
        }

        mp[p] = tot;
        tot = 0;
        if (mp[p] >= 1) cout << p << " " << mp[p] << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
