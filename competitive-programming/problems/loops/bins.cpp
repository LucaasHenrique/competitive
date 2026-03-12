#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, tot = 0;
    cin >> N;
    int seq[N];

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        seq[i] = n;
    }
    
    for (int i = 0; i < N; i++) {
        if (seq[i] == 1 && seq[i + 1] == 0 && seq[i + 2] == 0) {
            tot += 1;
        } 
    }
    
    cout << tot;

    return 0;
}
