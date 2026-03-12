#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 10;
#define ll long long

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll q; cin >> q;
    ll arr[maxn];
    ll prefix[maxn];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; 
    }
     
    prefix[0] = arr[0];
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    stringstream out;

    for (int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;

        out << prefix[r] - prefix[l - 1] << "\n";
    }

    cout << out.str();

    return 0;
}
