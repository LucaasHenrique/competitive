#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5+10;
int v[maxn];

int main (int argc, char *argv[]) {
        
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x; cin >> x; v[i] = x;
    } 
    
    ll s[maxn];
    s[0] = v[0];
    
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + v[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << s[r] - s[l - 1];
    }

    return 0;
}
