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

ll sum_digit(ll x) {    
    if (x < 10) return x;
    
    ll soma = 0;
    while (x > 0) {
        soma += x % 10;
        x = x / 10;
    } 

    return sum_digit(soma);
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        ll n; cin >> n;    
        if (n == 0) break;
        cout << sum_digit(n) << "\n";
    }

    return 0;
}
