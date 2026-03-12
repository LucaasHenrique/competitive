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

    vector<int> s(n + 1);
    bool stop = true;

    for (int x = 1; x * x <= n; x++) {
        for (int y = x + 1; x * x + y * y <= n; y++) {
            s[x * x + y * y]++;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 1) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    
    for (auto& a: ans) {
        cout << a << ' '; 
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
