#include <bits/stdc++.h>

using namespace std;
 
int fib(int n) {

    int s = 0;
    s++;

    if (n <= 1) return 1;

    cout << s;
    return fib(n - 1) + fib(n - 2);
}

int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fib(5);
    
 
    return 0;
}
