#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main (int argc, char *argv[]) {
    
    int n; cin >> n;
    ll x; cin >> x;

    vector<ll> weight;

    for (int i = 1; i <= n; i++) {
        ll m; cin >> m;
        weight.push_back(m);
    }

    sort(weight.begin(), weight.end());
    
    int c = 0, i = 0, j = weight.size() - 1;

    while (i <= j) {
        ll sum = weight[i] + weight[j];

        if (sum <= x) {
            c++;
            i++; j--;
        } else if (sum > x) { 
            c++;
            j--;
        } else {
            i++;
            c++;
        }
    }
    
    cout << c << "\n";

    return 0;
}
