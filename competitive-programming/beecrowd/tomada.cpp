#include <iostream>

using namespace std;

int main() {
 
    int T, sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> T;
        sum += T - 1;
    }

    cout << sum + 1 << endl;
    return 0;
}
