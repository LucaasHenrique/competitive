#include <bits/stdc++.h>

using namespace std;   

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    map<string, string> lang;
    vector<string> note;

    for (int i = 0; i < m; i++) {
        string s1, s2; cin >> s1 >> s2;
        lang[s1] = s2;
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        note.push_back(s);
    }

    for (auto s: note) {
        if (s.length() == lang[s].length()) {
            cout << s << "\n";
        } else if (s.length() > lang[s].length()){
            cout << lang[s] << "\n";
        } else {
            cout << s << "\n";
        }
    }

    return 0;
}
