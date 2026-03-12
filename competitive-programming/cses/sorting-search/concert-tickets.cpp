#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    multiset<ll> t;
    vector<ll> ct;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        t.insert(x);
    }
    
    //sort(t.begin(), t.end());
    for (int i = 0; i < m; i++) {
        ll x; cin >> x;
        auto s = t.upper_bound(x);

        if (s != t.begin()) {
            --s;
            cout << *s << "\n";
            t.erase(s);
        } else cout << -1 << "\n";
    }
    return 0;
}
