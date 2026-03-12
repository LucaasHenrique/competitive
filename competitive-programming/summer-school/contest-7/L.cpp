#include <bits/stdc++.h>

using namespace std;

#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define f first
#define s second
#define pb push_back
#define MAXN 300100
//1 1 1 3 3 3 5 5 5 7 7 7
// contar a qtd de pares e dividir por 2;
void solve() {
    int n; cin >> n; 
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int i = 0;

    sort(a.begin(), a.end());
    int c = 0;
    while (i < n-1) {
        if (a[i] == a[i+1]) {c++; i+= 2;}
        else i++;
    }

    cout << c/2 << '\n';
}



int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

