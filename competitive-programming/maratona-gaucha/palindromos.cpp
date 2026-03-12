#include <bits/stdc++.h>

using namespace std;

bool pali(string str) {
    return equal(str.begin(), str.end(), str.rbegin()); 
}

int main() {
    string s;
    cin >> s;
    
    if (pali(s)) {
        cout << 0;
        return 0;
    }
    
    string p = "";
    int index;
    
    for (int i = 0; i < s.length(); i++) {
        string suf = s.substr(i);
        
        if (pali(suf) && suf.size() > p.size()) {
            p  = suf;     
            index = i;
            break;
        }
    }
    
    cout << index; 
    return 0;
}
