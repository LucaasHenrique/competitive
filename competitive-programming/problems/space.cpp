#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    string s; cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }

    cout << "Thank you, " << s <<  ","<< " and farewell!" << "\n";
    return 0;
}
