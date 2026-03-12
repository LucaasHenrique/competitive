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

void solve() {
    int a, b; cin >> a >> b;

    int aux = 0;
    if (b % 10) {
        aux = b % 10;
        int al = b;
        b = a;
        a = al;
    } else aux = a % 10;

    // caso b non-special, com a troca;
    // a = 70, b = 17
    // b = a, a = b;
    // a - resto * b + resto * b;
    
    // a - resto x b + resto x a -> 70 - resto(7) x 17 + resto(7) x 70  -> o valor de a acaba sendo não especial
    // a x b - resto + resto * a -> 70 x 17 - resto(7) + resto(7) x 70; -> da certo para b non-special, mas para a non-special comete erros;
    cout << a - aux << " x " << b << " + " << aux << " x " << b << "\n";
}

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
