#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
    
    int mat[3][3];
    int soma = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }
    
    cout << "Diagonal principal: " << mat[0][0]+mat[1][1]+mat[2][2];
    cout << "Diagonal secundaria: " << mat[0][2]+mat[1][1]+mat[2][0];

    return 0;
}
