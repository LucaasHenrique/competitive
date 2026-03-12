#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main (int argc, char *argv[]) {
    int n;
    ll m;
    ll final = 0;

    cin >> n;
    set<ll> lista;

    for (int i = 1; i <= n; i++) {
        cin >> m;
        lista.insert(m);
    }

    for (ll i = 0; i < lista.size(); i++) {
        final++;
    }   


    cout << final << "\n";
    return 0;
}
