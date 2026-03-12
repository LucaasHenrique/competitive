#include <bits/stdc++.h>

using namespace std;

// compromisso
struct comp {
    int ini;
    int fim;
};

bool compara(comp a, comp b) {return a.fim < b.fim; }

int main (int argc, char *argv[]) {
        
    int n; cin >> n;
    vector<comp> c;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        c.push_back({x, y});
    }

    sort(c.begin(), c.end(), compara);

    int livre = 0;
    for (int i = 0; i < n; i++) {
        comp aux = c[i];

        if (aux.ini >= livre) {
            count++;
            livre = c[i].fim;
        }
    }

    cout << count << "\n";
    
    return 0;
}
