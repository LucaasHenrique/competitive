#include <bits/stdc++.h>

using namespace std;
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    while (cin >> s) { 
        int c = 0;
        stack<char> p;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(') 
                p.push(s[j]);
            if (s[j] == ')') {
                if (!p.empty())
                    p.pop();
            }
        }

        cout << (p.empty() ? "correct" : "incorrect"); 
     }
 
    return 0;
}
