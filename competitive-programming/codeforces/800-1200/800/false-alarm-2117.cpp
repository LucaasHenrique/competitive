#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    
    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n >> x;

        bool btn = false;
        int c = 0, t = 0;
        vector<int> s;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            s.push_back(a);
            if (a == 1) t++; 
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 0 && !btn) continue;
            else if (s[i] == 1 && c == 0) {c++; x--; btn = true;} 
            else {
                if (s[i] == 1 && x > 0) {c++; x--;}
                else x--; 
            }

            if (x == 0) break;
        }

        cout << (c == t ? "YES" : "NO") << "\n";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
