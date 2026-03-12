#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    ll tot = 0;
    ll tam = (n * (n +1))/2;
    for (int i = 0; i < n - 1; i++) {
        ll c; cin >> c; 
        tot += c;
    } 

    cout << tam - tot << "\n"; 
    return 0;
}
