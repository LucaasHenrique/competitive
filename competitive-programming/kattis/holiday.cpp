#include <bits/stdc++.h>

using namespace std;

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

    ll t, l, w, h; cin >> t;     
    range(i, 0, t) {
        cin >> l >> w >> h;

        if (l <= 20 && w <= 20 && h <= 20) {
            cout << "Case " << i + 1 << ": " << "good" << "\n";
        }
        else cout << "Case " << i + 1 << ": " << "bad" << '\n';
    } 

    return 0;
}
