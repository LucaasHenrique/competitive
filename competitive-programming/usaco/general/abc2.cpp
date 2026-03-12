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

    int vet[6];
    for (int i = 0; i < 6; i++) {
        cin >> vet[i];
    }

    sort(vet, vet + 6);
    
    //for (int i = 0; i < 6; i++) cout << vet[i] << " ";

    int p0 = vet[0];
    int A = 0;
    int B = 0;

    for (int i = 0; i <= p0; i++) {
        int t = p0 - i;
        if (t > 0 && i > 0 && i < t) {
            A = i;
            B = t;
            break;
        }
    }   
    
    int C = vet[1] - A;
    int D = vet[2] - A;
    cout << A << " " << B << " " << C << " " << D; 

    return 0;
}
