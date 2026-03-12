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

    int x, y, n;

    cin >> x >> y >> n;

    for (int i = 1; i <= n; i++) {
        
        if (i % x == 0 && i % y != 0) cout << "Fizz" << "\n";
        else if (i % y == 0 && i % x != 0) cout << "Buzz" << "\n";
        else if (i % y == 0 && i % x == 0) cout << "FizzBuzz" << "\n";
        else cout << i << "\n";
    }

    return 0;
}
