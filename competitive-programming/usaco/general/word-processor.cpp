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

    int n, k; 

    cin >> n >> k;

    int tam = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (i == 0) {
            tam = s.size();
            cout << s;
            continue;
        }
        if (tam + s.size() <= k) {
            tam += s.size();
            cout << " " << s;
        } else {
            tam = s.size();
            cout << "\n" << s;
        }
    }

    return 0;
}
