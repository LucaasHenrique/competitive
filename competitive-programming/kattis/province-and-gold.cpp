#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int g, s, c; cin >> g >> s >> c;

    g = 3 * g;
    s = 2 * s;
    c = 1 * c;
    
    int bp = g + s + c;
    
    if (bp >= 6) cout << "province or gold";
    if (bp == 2) cout << "estate or copper";
    if (bp == 5) cout << "duchy or silver";
    if (bp == 1) cout << "copper";
    
    return 0;
}
