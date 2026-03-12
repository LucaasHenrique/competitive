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

    map<int, int> mp;
    vector<int> v;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        v.push_back(a);
        mp[a] = i;
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++) {
        auto it = mp.find(v[i]);
        if (it != mp.end()) {
            cout << it->second << " ";
        }
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
