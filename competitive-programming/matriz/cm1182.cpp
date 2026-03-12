#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    double mat[12][12];
    int C;
    char T;

    cin >> C >> T;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> mat[i][j];
        }
    }

    double sum = 0;
    
    for (int i = 0; i < 12; i++) {
        sum += mat[i][C];
    }
    
    cout << fixed << setprecision(1);
    cout << (T == 'S' ? sum : sum / 12); 

    return 0;
}
