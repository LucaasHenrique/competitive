#include <bits/stdc++.h>

using namespace std;

#define PB push_back

int main (int argc, char *argv[]) {
    
    int N; cin >> N;
    int M;
    char L;
    vector<int> tam;
    vector<char> sap; 
    int sum = 0;
    

    for (int i = 0; i < N; i++) {
        cin >> M >> L;
        tam.PB(M);
        sap.PB(L); 
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (tam[i] == tam[j] && sap[i] != sap[j]) {
                sum += 1;
            }
        }
    }

    cout << sum; 

    return 0;
}
