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
    string s;
    int temp = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'a') {
            t++;
        } else if (t < 2) {
            t = 0;
        } else {
            if (t > 1) {
                temp += t;
            }
            t = 0;
        }
    }
    if (t > 1) {
        temp += t;
    } 
    cout << temp;

    return 0;
}
