#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N; cin >> N;
    vector<string> r;

    for (int i = 0; i < N; i++) {

        string A, B; cin >> A >> B;
        int pos = B.length();

        if (A.find(B) != string::npos && A.find(B) == (A.length() - pos)) {
            r.push_back("encaixa");
        } else {
            r.push_back("nao encaixa");
        }
    } 

    for (auto s: r) {
        cout << s << endl;
    }

    return 0;
}
