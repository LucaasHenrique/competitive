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
    
    /*ifstream cin("teleport.in");
    ofstream cout("teleport.out"); */

    int a, b, x, y;

    cin >> a >> b >> x >> y;

    int mind = 0;
    
    mind = min(abs(a - b), min((abs(a - x) + abs(b - y)), (abs(a - y) + abs(b - x))));

    cout << mind << "\n";

    return 0;
}
