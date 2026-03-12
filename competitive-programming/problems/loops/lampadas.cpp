#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, A = 0, B = 0, I = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> I; 
        if (I == 1) {
            A ^= 1;
        } else if (I == 2) {
            A ^= 1;
            B ^= 1;
        }
    }

    cout << A << B << endl;
    return 0;
}
