#include <bits/stdc++.h>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
   
    map<char, double> notas;
    notas['W'] = 1;
    notas['H'] = 0.5;
    notas['Q'] = 0.25;
    notas['E'] = 0.125;
    notas['S'] = 0.0625;
    notas['T'] = 0.03125;
    notas['X'] = 0.015625;

    string h;
    vector<int> res;
    while (true) {
        cin >> h;
        
        if (h == "*") {
            break;
        }

        double s = 0;
        int c = 0;

        for (int i = 1; i < h.size(); i++) {
            if (notas.find(h[i]) != notas.end()) {
                s += notas[h[i]];
            }

            if (h[i] == '/') {
                if (s == 1) {
                    c++;
                }
                s = 0;
            }
        }

        res.push_back(c);
    } 
            


    for (auto r: res) {
        cout << r << endl;
    }

    return 0;
}
