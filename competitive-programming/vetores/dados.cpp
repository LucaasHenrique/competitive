#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N; 
    cin >> N;
    vector<int> lan(13, 0);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        lan[n]++;
    }

    int tot = 0;
    
    for (int i = 1; i < 12; i++) {
        if (lan[i] > tot) {
            tot = lan[i];
        }
    }
    
    for (int i = 1; i < 12; i++) {
        if (lan[i] == tot) {
            cout << i << " ";
        }
    }

    return 0;
}
