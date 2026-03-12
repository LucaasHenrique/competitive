#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int busca (vector<ll> v,  ll x) {
    int mid;
    int ini = 0;
    int fim = v.size() - 1;

    while (ini < fim) {
        mid = (ini + fim) / 2;

        if (x >= v[mid]) {
            ini = mid + 1;
        } else {
            fim  = mid;
        }
    }

    if (ini < x && v[ini] <= x) {
        ini++;
    }

    return ini;
}

int main (int argc, char *argv[]) {
    
    int n, m;
    cin >> n >> m;

    vector<ll> A(n - 1);
    vector<ll> F(n);
    vector<ll> O(m);

    for (int i = 0; i < n - 1; i++) {
        ll a; cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        ll f; cin >> f;
        F.push_back(f);
    }

    for (int i = 0; i < m; i++) {
        ll o; cin >> o;
        O.push_back(o);
    }
    
    sort(A.begin(), A.end());
    
    auto i = lower_bound(A.begin(), A.end(), 2);
    cout << F[*i] << "\n";

    return 0;
}
