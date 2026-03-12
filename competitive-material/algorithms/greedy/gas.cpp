#include <bits/stdc++.h>

using namespace std;

struct gas {
    double preco;
    double estoq;
};

bool compara(gas x, gas y) {return x.preco < y.preco; }

int main (int argc, char *argv[]) {
   
    int n; 
    double d;

    cin >> n >> d;
    double custo;
    vector<gas> forn;

    for (int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        forn.push_back({x, y}); 
    }

    sort(forn.begin(), forn.end(), compara);

    for (int i = 0; i < n; i++) {
        gas davez = forn[i];

        if (davez.estoq < d) {
            custo += davez.estoq * davez.preco;
            d -= davez.estoq;
        } else {
            custo += d * davez.preco;
            d = 0;
            break;
        }
    }

    if (d) cout << "impossivel" << "\n";
    else cout << custo << "\n";

    return 0;
}
