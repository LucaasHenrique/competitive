#include <iostream>

using namespace std;

int campo[55];

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> campo[i]; 
    }
    
    for (int i = 1; i <= n; i++) {
        cout << campo[i - 1] + campo[i] + campo[i + 1] << "\n"; 
    }

    return 0;
}
