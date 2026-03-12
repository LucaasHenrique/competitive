#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {

    int A, B, C;
    
    cin >> A >> B;
    
    C = (A + B) / 2;

    if ((A + B + C) / 3 == (min(A, (min(B, C))) + max(A, max(B, C)))/ 2) {
        cout << C << endl;
    } else {
        while ((A + B + C) / 3 != (min(A, (min(B, C))) + max(A, max(B, C)))/ 2) {
            C--;
        }
    }   

    cout << C << endl;

    return 0;
}
