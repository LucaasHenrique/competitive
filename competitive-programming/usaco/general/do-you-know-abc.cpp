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
    
    int A = 0, B = 0, C = 0;
    vector<int> s(7);
    for (int i = 0; i < 7; i++) {
        cin >> s[i];
    }
    
    sort(s.begin(), s.end());

    A = s[0];
    B = s[1];

    C = s[6] - A - B;

    cout << A << "\n" << B << "\n" << C << "\n";

    return 0;
}
