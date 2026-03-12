#include <bits/stdc++.h>

using namespace std;
#define pb push_back
void solve() {
    
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), me(n+m);
    
    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i <m ; i++) cin >> b[i];
    
    int i = 0, j = 0;
    
    int k = min(n, m);
    while (i < n && j < m) {
        if (a[i] <= b[j]) {cout << a[i] << " "; i++;}
        else {cout << b[j] << " "; j++;}
    }
    
    while (i < n) {cout << a[i] << " "; i++;}
    while (j < m) {cout << b[j] << " "; j++;}
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
