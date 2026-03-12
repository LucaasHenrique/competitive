#include <bits/stdc++.h>

using namespace std;

#define MAX 100100

int tam1, tam2, vetor1[MAX], vetor2[MAX], vetor[MAX];

void fnmerge() {

    int tam = 0;
    int j = 1;

    for (int i = 1; i <= tam1; i++) {

        while (j <= tam2 && vetor2[j] < vetor1[i]) {
            tam++;

            vetor[tam] = vetor2[j];
            j++;
        }

        tam++;
        vetor[tam] = vetor1[i];
    }
    
    while (j <= tam2) {
        tam++;

        vetor[tam] = vetor2[j];
        j++;
    }
}

int main (int argc, char *argv[]) {
    
    cin >> tam1;
        
    
    for (int i = 1; i <= tam1; i++) cin >> vetor1[i];
   
    cin >> tam2;

    for (int i = 1; i <= tam2; i++) cin >> vetor2[i];

    fnmerge(); 

    for (int i = 1; i <= tam1 + tam2; i++) cout << vetor[i];

    return 0;
}
