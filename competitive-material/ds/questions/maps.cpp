#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    map<int, string> m;
    m[1] = "monkey";
    m[3] = "banana";
    m[5] = "magic";

    cout << m[3] << endl;
    cout << m[2] << endl;
    cout << m.count(3) << endl;

    for (auto x: m) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
