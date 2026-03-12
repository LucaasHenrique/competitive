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
    vector<int> c(n);

    ll ant = 0;
    ll mov = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int diff = 0;
        if (i == 0) {
            ant = a;
        }

        if (a < ant) {
            mov += abs(ant - a);
            diff = abs(ant - a);
        }

        ant = a + diff;
    }

    cout << mov << "\n";

    return 0;
}
