#include <bits/stdc++.h>

using namespace std;
 
int main() {
 
    int N; cin >> N;
    int s;
    
    for (int i = 0; i < N; i++) {
        s = 0;
        double k; cin >> k;
        
        while (k > 1) {
            k -= k * 0.5;
            s++;
        }
        
        cout << s << "dias" << endl;
    }
    
 
    return 0;
}
