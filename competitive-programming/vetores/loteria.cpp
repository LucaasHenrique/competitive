#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N = 6, tot = 0;

    int numflav[N];
    int sorteados[N];

    for (int i = 0; i < N; i++) {
        cin >> numflav[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> sorteados[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (numflav[i] == sorteados[j]) {
                tot++;
            }
        }
    }

    if (tot == 3) cout << "terno";
    if (tot == 4) cout << "quadra";
    if (tot == 5) cout << "quina";
    if (tot == 6) cout << "sena";
    if (tot < 3) cout << "azar";

    return 0;
}
