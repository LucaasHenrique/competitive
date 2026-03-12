#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int num;
    int maior = 0;

    while (true) {
        cin >> num;
        
        if (num > maior) {
            maior = num;
        }

        if (num == 0) {
            break;
        }
    }   

    cout << maior << endl;

    return 0;
}
