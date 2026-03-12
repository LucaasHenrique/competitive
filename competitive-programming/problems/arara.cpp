#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, M; cin >> N >> M;

    int i = 0, s = 0, c = 0;

    if (N == 1) {
        c = 1; 
    }

    while (i < M && s < M) {
        if (i == s) {
            s += 5;
            c++;
        }

        i++;
    }
    
    cout << s;
    cout << (c == N ? "S": "N") << endl;

    return 0;
}
