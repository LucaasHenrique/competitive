#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N = 10;
    int vector<int> par;
    int vector<int> impar;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            par.push_back(num);
        } else {
            impar.push_back(num);
        }
    }

    cout << "Pares: ";
    for (int n : par)
        cout << n << " ";
    cout << endl;

    cout << "Ímpares: ";
    for (int n : impar)
        cout << n << " ";
    cout << endl;

    return 0;
}
