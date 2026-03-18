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

    for (int k = 0; k < t; k++) {
        int n; cin >> n;
        int c = 0;
        vector<int> o(n+1);
    
        if (n == 1) {cout << 0; return;}

        for (int t = 1; t <= n; t++) {
            cin >> o[t];
        }

        int i = 1, j = 2;

        while (i <= n && j <= n && n > 2) {
            if (o[i] > o[j] && j > i) {
                n--;
                i = o[j] - 1;
                o.erase(o.begin() + j);
                j = o[i] - 1;
                c++;
            } else {j++;i++;}
        }

        cout << c;
    }


}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
