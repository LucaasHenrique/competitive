#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long

int main (int argc, char *argv[]) {
    
    ll n; cin >> n;
    bool v = false; 
    string s;
    ll i = 1;

    while (true) {
        ll r = (ll) n * i;
        
        s = to_string(r);
        
        v = true;    
        for (char a: s) {
            if (a != '1' && a != '0') {
                v = false;
                break;
            } 
        }
            
        if (v) {
            break;
        }

        i++;
    }
    
    cout << s << "\n";

    return 0;
}
