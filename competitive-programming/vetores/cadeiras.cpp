#include <bits/stdc++.h>

using namespace std;
int sort_cadeiras(int numsort) {
    int c = 0, num = 1;
    while (c < numsort) {
        if (num > 2) {
            num = 0;
        }
        c++;
        num++;
    }

    return num;
}

int main (int argc, char *argv[]) {
    
    int A, B, C;
    int cadA, cadB;
    cin >> A >> B;
    
    cadA = sort_cadeiras(A);
    cadB = sort_cadeiras(B);
    
    if (cadB == cadA) {
        cadB = cadB + 1;
    }

    if (cadA == cadB) {
        cadA = cadA + 1;
    }

    if (cadA == 1 && cadB == 0 || cadA == 0 && cadB == 1) {
        cout << 2;
    }
    
    if (cadA == 1 && cadB == 2 || cadA == 2 && cadB == 1) {
        cout << 0;
    }

    if (cadA == 0 && cadB == 2 || cadA == 2 && cadB == 0) {
        cout << 1;
    }

    cout << cadA;

    return 0;
}
