#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    
    int P1, P2, C1, C2;

    cin >> P1 >> C1 >> P2 >> C2;

    if (P1 * C1 == P2 * C2) cout << 0 << endl;

    if (P1 * C1 != P2 * C2 && P1 * C1 > P2 * C2) {
        cout << -1 << endl;
    } else if  (P1 * C1 != P2 * C2 && P1 * C1 < P2 * C2){
        cout << 1 << endl;
    }
    
    return 0;
}
