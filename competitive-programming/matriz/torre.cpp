#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N; cin >> N;
    
    int mat[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
   
    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                sum += mat[i][j];
            }
        }
    }

    cout << sum;
    return 0;
}
