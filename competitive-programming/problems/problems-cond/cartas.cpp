#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    
    int A, B, C;
    cin >> A >> B >> C;

    if (A != B && A != C) cout << A << endl;
    if (B != A && B != C) cout << B << endl;
    if (C != A && C != B) cout << C << endl;   


    return 0;
}
