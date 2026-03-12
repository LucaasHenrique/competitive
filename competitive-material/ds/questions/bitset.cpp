#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));
    cout << (a&b) << "\n";
    cout << (a|b) << "\n";
    cout << (a^b) << "\n";

    return 0;
}
