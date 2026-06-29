#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<long long> factorize(long long n) {
    vector<long long> f;
    for (long long p = 2; p * p <= n; p++)
        while (n % p == 0) { f.push_back(p); n /= p; }
    if (n > 1) f.push_back(n);
    return f;
}

/*long long num_divisors(long long n) {
    long long res = 1;
    for (auto [p, e] : factorize(n))
        res *= (e + 1);
    return res;
}

// σ(n) = Π (p^(e+1)-1)/(p-1)
long long sum_divisors(long long n) {
    long long res = 1;
    for (auto [p, e] : factorize(n)) {
        long long pk = 1, sum = 0;
        for (int i = 0; i <= e; i++) { sum += pk; pk *= p; }
        res *= sum;
    }
    return res;
}*/

int main() {
    int n; cin >> n;
    int cnt = 0;
    int p = 2;

    while (p * p <= n) {
        while (n % p == 0) {
            cnt++;
            n /= p;
        }

        p++;
    }

    if (n > 1) cnt++;

    cout << cnt;
}
