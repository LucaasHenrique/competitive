#include <bits/stdc++.h>

using namespace std;

int mdc(int a,int b) {
    int R;
    while ((a % b) > 0)  {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}

int main (int argc, char *argv[]) {
    
    int N, F1, F2; 
    cin >> N;
    int res[N];

    for (int i = 0; i < N; i++) {
        cin >> F1 >> F2;
        res[i] = mdc(F1, F2);
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}
