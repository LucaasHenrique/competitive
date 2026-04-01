#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, aux;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> aux;
        if (n < 3) 
            cout << n << " ";
        
        else 
            cout << 2 << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t=1;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}
