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
#define sec second
#define pb push_back
#define MAXN 300100

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int i = 0, c = 0; 
    while (i < s.size()) {
        int j = i;
        if (s[i] == 'B') { 
            for (int j; j < k-1; j++) {
                s[j] = 'W';
            }

            c++; i += k;
        } else {
            i++;
        }
    }

    cout << c << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();
    return 0;
}
