#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
    
    int mat[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }

    int maior = mat[0][0];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] > maior) {
                maior = mat[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == maior) {
                mat[i][j] = -1;
            } 
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j]; 
        }
    }
}
