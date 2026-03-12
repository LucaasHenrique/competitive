#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <string>

using namespace std;

string crip(string m) {
    string w = "";

    for (int i = 0; i < m.size(); i++) {
        char c = m[i];
        if (isalpha(c)) {
            w += char(c + 3);
        } else w += c;
    }

    return w;
}

int main (int argc, char *argv[]) {
    
    int N; cin >> N;
    cin.ignore();
        
    for (int i = 0; i < N; i++) {
        string m;
        getline(cin, m);
        m = crip(m);

        reverse(m.begin(), m.end());

        for (size_t j = m.size() / 2; j <= m.size(); j++) {
            m[j] = m[j] - 1;
        }

        cout << m << endl;
    }

    return 0;
}
