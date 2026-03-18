#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    int x = 0, y = 0;
    int c = 0;

    int kaux = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'U') y++;  
        else if (s[i] == 'R') x++;

        if (x == y && x > 0 && y > 0) {
            if (s[i] == 'U' && s[i + 1] == 'U') c++;
            if (s[i] == 'R' && s[i + 1] == 'R') c++;
        }
    }

    cout << c << "\n";

    return 0;
}
