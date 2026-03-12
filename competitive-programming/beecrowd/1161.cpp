#include <bits/stdc++.h>

// soma de fatoriais

using namespace std;

long long fat (long long n) {
    if (n <= 1) return 1;
    
    return n * fat(n - 1);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long int x, y;
    long long int s;

    while (cin >> x >> y) {
        s = fat(x) + fat(y);
        cout << s << endl;
    }

    return 0;
}
