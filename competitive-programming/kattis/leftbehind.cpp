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
    
    int x, y;

    int i = 0;
    while (true) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        
        if (x + y == 13) {
            cout << "never speak again" << "\n";
            if (i == 0) break;
        }
        
        if (x > y) cout << "to the convetion" << "\n";
        else if (y > x && x + y != 13) cout << "left beehind" << "\n";

        if (x == y) cout << "undecided" << "\n";

        i++;

    }

    return 0;
}
