#include <bits/stdc++.h>

// Pouca Frequência

using namespace std;

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;

        for (int j = 0; j < N; j++) {
            string a; cin >> a;
            string p; cin >> p;
            int c = 0, m = 0; 

            for (int k = 0; k < p.size(); k++) {
                if (p[k] == 'P') c++;

                if (p[k] == 'M') m++;
            }

        }
    }


    return 0;
}
