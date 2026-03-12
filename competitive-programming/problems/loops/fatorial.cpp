#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, res = 1; 

    cin >> N;

    for (int i = N; i > 0; i--) {
        res *= i;
    }

    cout << res << endl; 

    return 0;
}
