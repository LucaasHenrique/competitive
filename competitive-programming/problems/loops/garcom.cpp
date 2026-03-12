#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, L, C, broke = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        
        cin >> L >> C;
        if (L > C) {
            broke += C;
        }
    }
    
    cout << broke;

    return 0;
}
