#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)

int dec(int n) {
    int sum = 0;
    while (n > 0) {
        int num = n % 10;
        sum += num * num;
        n /= 10;
    }

    return sum;
}

void solve() {
    int n; cin >> n;
        
    int s = dec(n);
    set<int> ss; 
    while (s != 1) {
        s = dec(s);

        if (ss.count(s)) {cout << "No" << "\n"; return;}; 
        
        ss.insert(s);
    }

    cout << "Yes" << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
