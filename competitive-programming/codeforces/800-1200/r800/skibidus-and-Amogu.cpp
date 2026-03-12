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
        string s; cin >> s;

        if (s.size() <= 2) {
            cout << 'i'<< "\n";
        } else {
            
            int pos = s.rfind("us");
            s[pos] = 'i';
            s[s.size()-1] = ' ';

            cout << s << '\n';
        }

    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
