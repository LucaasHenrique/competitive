#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    
    int X, Y;
    cin >> X >> Y;
    
    if (X == 0 || Y == 0) {
        cout << "eixos";
    } else if (X > 0 && Y > 0) {
        cout << "Q1";
    } else if (X < 0 && Y > 0) {
        cout << "Q2";
    } else if (X < 0 && Y < 0) {
        cout << "Q3";
    } else { // X > 0 && Y < 0
        cout << "Q4";
    }

    return 0;
}
