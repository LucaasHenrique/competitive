#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

// cifra de cesar

string cifra (const string& s, int l) {
    string r = "";
    for (size_t i = 0; i < s.size(); i++) {
        int c = s[i];
        int pos = c - 'A';
        
        int npos = (pos - l + 26) % 26;

        r += char ('A' + npos);
    }
    
    return r;
}

int main (int argc, char *argv[]) {
    
    int N; cin >> N;
    int l;
    

    for (int i = 0; i < N; i++) {
        string w; cin >> w;
        cin >> l;
        
        cout << cifra(w, l);
    }

    return 0;
}
