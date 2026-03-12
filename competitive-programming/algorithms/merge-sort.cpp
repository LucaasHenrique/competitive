#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int vetor[MAX], aux[MAX];

void merge_sort(int ini, int fim) {

    if (ini == fim) return;

    merge_sort(ini, (ini + fim) / 2);
    merge_sort((ini + fim) / 2 + 1, fim);

    int tam = 0;
    int j = (ini + fim) / 2 + 1;

    for (int i = ini; i <= (ini + fim)/2; i++) {

        while (j <= fim && vetor[j] < vetor[i]) {
            aux[tam] = vetor[j];
            tam++;
            j++;
        }

        aux[tam] = vetor[i];
        tam++;
    }

    while (j <= fim) {
        aux[tam] = vetor[j];
        j++;
        tam++;
    }

    for (int i = ini; i <= fim; i++) vetor[i] = aux[i - ini];
}

int main (int argc, char *argv[]) {
    
    
    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> vetor[i];

    merge_sort(1, n);

    for (int i = 1; i <= n; i++) cout << vetor[i];

    return 0;
}
