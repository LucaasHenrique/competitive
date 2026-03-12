#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    char o; cin >> o;
    double mat[12][12];
    double sum = 0;
    double c = 0;
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++){
            int v;
            cin >> v;

            if (i + j >= 12) {
                sum += v;
                c += 1;
            }
        }
    }

    cout << (o == 'S' ? sum : sum / c) << endl;

    return 0;
}
