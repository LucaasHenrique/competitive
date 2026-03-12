#include <iostream>

using namespace std;

const int MAX_TAMANHO = 1000000;
int v[MAX_TAMANHO];

int main (int argc, char *argv[]) {
    int tamanho = 0, qtd_op;

    cin >> qtd_op;

    for (int i = 0; i < qtd_op; i++) {
        int tipo;
        cin >> tipo;

        if (tipo == 0) {
            int x;
            cin >> x;
            
            v[tamanho] = x;
            tamanho++; 
        } else {
            tamanho--;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";
    return 0;
}
