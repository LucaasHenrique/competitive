#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main (int argc, char *argv[]) {
    
    int n; cin >> n;
    vector<int> c;

    for (int i = 0; i <= n; i++) { int x; cin >> x; c[i] = x;}
    
    int i = 0, ct = 1;
    for (int i = 0; i <= n; i++) {
        if (c[i + 1] > c[i]) {
            ct++;
        }
    } 

    cout << ct << "\n";

    return 0;
}
