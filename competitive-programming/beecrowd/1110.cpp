#include <bits/stdc++.h>

// jogando cartas fora

using namespace std;

int main() {
        
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        int N; cin >> N;    
        if (N == 0) break;
            
        deque<int> cartas;
        vector<int> ds;

        for (int i = 1; i <= N; i++) {
            cartas.push_back(i);
        }
    
        while (cartas.size() >= 2) {
            ds.push_back(cartas.front());

            cartas.pop_front();
            cartas.push_back(cartas.front());
            cartas.pop_front();
        }
    
        cout << "Discarded cards:";
        if (!ds.empty()) {
            cout << " ";
            for (size_t i = 0; i < ds.size(); ++i) {
                if (i) cout << ", ";
                cout << ds[i];
            }
        }
        cout << "\n";

        cout << "Remaining card: " << cartas.front() << "\n";
    }
    
    return 0;
}
