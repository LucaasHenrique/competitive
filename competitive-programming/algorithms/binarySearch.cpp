#include <iostream>

using namespace std;

int binary_search(int *vetor, int num) {
    cout << sizeof(vetor) << "\n";
    cout << sizeof(vetor[0]) << "\n";
    
    int inicio = 0;
    int fim = sizeof(vetor) / sizeof(vetor[0]) - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == num) {
            return meio;
        } else if (vetor[meio] > num) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

int main (int argc, char *argv[]) {
    
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << binary_search(vetor, 5) << "\n";

    return 0;
}
