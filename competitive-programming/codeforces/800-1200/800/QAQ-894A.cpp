#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve() {
    string s; cin >> s;

    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i+1; j < s.size(); j++) {
            for (int k = j + 1; k < s.size(); k++) {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
                    c++;
                }
            }
        }
    }

    cout << c;
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
