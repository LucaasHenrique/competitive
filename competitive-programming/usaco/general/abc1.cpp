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

    int vet[4];
    for (int i = 0; i < 4; i++) {
        cin >> vet[i];
    }

    sort(vet, vet + 4);
    
    int A = vet[0];
    int B = vet[3] / A;

    cout << A << " " << B;

    return 0;
}
