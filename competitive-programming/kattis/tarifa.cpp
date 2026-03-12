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

    int x, n; cin >> x >> n;

    int sum = 0;
    while (n--) {
        int y; cin >> y;

        if (y == x) continue;

        if (y < x) {
            sum += x - y;
        } else if (y > x) sum -= abs(x - y);
    }


    cout << sum + x << "\n";
    return 0;
}
