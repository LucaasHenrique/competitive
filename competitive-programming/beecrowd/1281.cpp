#include <bits/stdc++.h>

using namespace std;
 
int main() {
 
    int N, M, P; cin >> N;
    vector<double> res; 
    for (int j = 0; j < N; j++) {
        double s = 0;
        
        map<string, double> pd;
        cin >> M;

        for (int i = 0; i < M; i++) {
            string prod; cin >> prod;
            double p; cin >> p;

            pd[prod] = p;
        }

        cin >> P;

        for (int i = 0; i < P; i++) {
            string prod; cin >> prod;
            double q; cin >> q;

            if (pd.find(prod) != pd.end()) {
                s += pd[prod] * q;
            }   

        }

        res.push_back(s);
    }

    for (auto s: res) {
        cout << "R$ "<< s << endl;
    }

    return 0;
}
