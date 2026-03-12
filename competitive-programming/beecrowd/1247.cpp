#include <bits/stdc++.h>

// Guarda Costeira

using namespace std;

int main (int argc, char *argv[]) {
    
    int D, VF, VG;

    while (cin >> D >> VF >> VG){
        
        double tf = 12.0 / VF;
        double tg = sqrt((D*D) + 144) / VG;

        if (tg < tf) cout << "S" << endl;
        else cout << "N" << endl;
    }

    return 0;
}
