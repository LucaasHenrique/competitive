#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtpalavras;
    string two = "two";

    cin >> qtpalavras;
    

    for (int i = 0; i < qtpalavras; i++) {
        string w; cin >> w;

        if (w.size() == 5) cout << 3 << endl;
        
        int d = 0;

        for (int j = 0; j < 3; j++) {
            if (w[j] != two[j]) d++;
        }

        if (d > 1) cout << 1 << endl;
        else cout << 2 << endl; 
    }

    return 0;
}
