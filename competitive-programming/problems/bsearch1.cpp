#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, q; 
vector<int> v;


int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    while (q--) {
        int x; cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);

        if (*it == x) {
            cout << (it - v.begin()) << "\n";
        }
        else cout << -1 << '\n';
    }

    return 0;
}
