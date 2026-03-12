#include <bits/stdc++.h>
#include <variant>

using namespace std;

int main (int argc, char *argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ifstream arq("arq.txt");
    
    string l;
    string w = "";

    bool s = false;
    while(getline(arq, l)) {
        if (l.rfind(".......", 0) == 0) {
            s = true;
            break;
        }
    }

    if (s) {
        arq.clear();
        arq.seekg(0);
        int c = 0;
        while(arq >> l) {
            if (c == 0) w += l;           
            else w += " " + l;
            c++;
        }
    }
    string r = w;
    vector<int> q;
    int t = r.size();
    string sub = "line";
    int f = 0;

    while (f != t) {
        size_t pos = r.find(sub);
        if (pos != variant_npos) {
            if (f == 0) cout << pos << "\n";
            else cout << pos + sub.size() << "\n";
            r.erase(pos, sub.size()); 
        }
        
        f++;
    }

    cout << w;
    arq.close();

    return 0;
}
