#include <bits/stdc++.h>

using namespace std;
#define ll long long;

int main (int argc, char *argv[]) {
    
    string s; cin >> s;

    int temp = 1;
    vector<int> c;
   
    if (s.size() == 1) cout << temp; 
    else {
        for (auto i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                temp++;
            } else if (s[i] != s[i + 1]) {
                temp = 1;
            }

            c.push_back(temp);
        }
        cout << *max_element(c.begin(), c.end()) << "\n";
    }
    
    return 0;
}
