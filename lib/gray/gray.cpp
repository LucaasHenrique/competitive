#include <iostream>

using std::cout;

int g (int n) {
    return n ^ (n >> 1);
}

int32_t main() {
    int n = 5;

    cout << g(n) << "\n";

    return 0;
}
