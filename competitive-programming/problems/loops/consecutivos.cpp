#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
        
    int N, V, maior_seq = 1, atual = 1;
    cin >> N;
    int aux[N];

    for (int i = 0; i < N; i++) {
        cin >> aux[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (aux[i] == aux[i + 1]) {
            atual += 1;
        } else {
            atual = 1;
        }

        maior_seq = max(maior_seq, atual);
    }
    
    cout << maior_seq << endl;

    return 0;
}
