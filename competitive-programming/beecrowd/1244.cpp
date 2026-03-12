#include <bits/stdc++.h>
#include <cctype>

using namespace std;

string split(string w) {
    istringstream iss(w);
    string p;
    string words;
    while (iss >> p) {
        words.push_back(p);
    }

    return words;
}

bool is_small(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    return tolower(a[0]) < tolower(b[0]);
}

int main (int argc, char *argv[]) {
    
    int N; cin >> N;
    vector<string> words;

    for (int i = 0; i < N; i++) {
        string w;
        getline(cin >> ws, w);

        string p = split(w);

        sort(p.begin(), p.end(), is_small);
    
        string ww;
        bool first = true;
        for (string s : p) {
            if (!first) ww += " ";
            ww += s;
            first = false;
        } 

        words.push_back(ww);
    }
    
    for (string w: words) {
        cout << w << " " << endl;
    }

    return 0;
}
