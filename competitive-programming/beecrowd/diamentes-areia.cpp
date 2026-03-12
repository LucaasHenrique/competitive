#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    int n; cin >> n;
    string a;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        int c = 0;
        for (int j = 0; j < a.size();) {
            if (a[j] == '.')
                a.erase(j, 1);  
            else
                j++;
        }

        for (int j = 0; j + 1< a.size();) {
            if (a[j] == '<' && a[j + 1] == '>') {
                a.erase(a.begin() + j, a.begin() + j + 2);
                c++;
                j = 0;
            }
            else
                j++;
        }   
        
        cout << a << "\n";
        cout << c << "\n";
    }
 
    return 0;
}
