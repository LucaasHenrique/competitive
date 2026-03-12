#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, A, C = 0, sum = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A;
        sum += A;
        C++;

        if (sum >= 1000000) {
            break; 
        }
    }
    
    cout << C;
    return 0;
}
