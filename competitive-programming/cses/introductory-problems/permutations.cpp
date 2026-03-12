#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

void solve(int n) {
    
    if (n <= 3 && n >= 2) {
        cout << "NO SOLUTION";
        return;
    }

    for (int  i= 2; i <= n; i += 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    solve(n);

    return 0;
}
