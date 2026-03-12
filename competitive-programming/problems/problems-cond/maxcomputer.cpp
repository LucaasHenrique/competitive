#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, P, Q;
    char C;

    cin >> N; 
    cin >> P >> C >> Q;

    if (C == '+') {
        if (P + Q <= N) {
            cout << "OK";
        } else {
            cout << "OVERFLOW";
        }
    } else if (C == '*') {
        if (P * Q <= N) {
            cout << "OK";
        } else {
            cout << "OVERFLOW";
        }
    }


    return 0;
}
