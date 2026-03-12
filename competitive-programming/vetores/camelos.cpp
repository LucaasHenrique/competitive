#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, P, sum = 0,  med = 0;
    cin >> N;
    
    int pesos[N];

    for (int i = 0; i < N; i++) {
        cin >> P;
        pesos[i] = P;
        sum += P;
    }

    med = sum / N;

    for (int i = 0; i < N; i++) {
        cout << med - pesos[i] << endl;
    }

    return 0;
}
