#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int A, B;

    cin >> A >> B;

    if (A < B) {
        for (int i = A; i <= B; i++) {
            cout << i << " ";
        }
    } else {
        for (int i = B; i <= A; i++) {
            cout << i << " ";
        }
    }

    return 0;
}
