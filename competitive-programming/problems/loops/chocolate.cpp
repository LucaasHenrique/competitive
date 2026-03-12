#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, num, tot = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        tot += num - 1;
    }

    cout << tot << endl;

    return 0;
}
