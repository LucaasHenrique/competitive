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

    int n; cin >> n; 

    int p = 0;
    while (n--) {
        int x; 
        int c = 0;
        for (int i = 0; i < 3; i++) {    
            cin >> x;

            if (x == 1) c++;
        }

        if (c >= 2) p++;
    }

    cout << p << "\n";

    return 0;
}
