#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main (int argc, char *argv[]) {
    
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> dsize;
    vector<ll> aps;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        dsize.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        ll x; cin >> x;
        aps.push_back(x);
    }
    
    sort(dsize.begin(), dsize.end());
    sort(aps.begin(), aps.end());

    int c = 0; int i = 0; int j = 0;

    while (i < dsize.size() && j < aps.size()) {
        if (abs(dsize[i] - aps[j]) <= k) {
            c++;
            i++, j++; 
        } else if (dsize[i] < aps[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << c << '\n';

    return 0;
}
