#include <algorithm>
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
    vector<int> v(n);
    vector<int> vo(n);
    for (int i = 0; i < n; i++) {
       cin >> v[i];
       vo[i] = v[i];
    }


    sort(vo.begin(), vo.end());
    map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        mp[vo[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        v[i] = mp[v[i]];
    }
    
    for (auto p: v) {
        cout << p << " ";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
