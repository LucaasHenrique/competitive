#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int mat[3][3];
    int suml = 0, sumc = 0;    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            cin >> mat[i][j];
        }
    }

    int dig1 = 0, dig2 = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            if (i == j) {
                dig1 += mat[i][j];
            }
            if (i + j == 3 - 1) {
               dig2 += mat[i][j];
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            sumc += mat[j][i];
            suml += mat[i][j];
        }
    }

    cout << ((dig1 == dig2) && (dig1 == sumc / 3) && (dig1 == suml / 3) ? "SIM" : "NAO") << endl; 

    return 0;
}
