#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main (int argc, char *argv[]) {
    
    ll n; cin >> n;
    cout << n << " ";
    
    while (true) {
        if (n == 1) break;
        if (n % 2 == 0)
            n = n / 2;
        else 
            n = (n * 3) + 1;

        cout << n << " ";
    }

    return 0;
}
