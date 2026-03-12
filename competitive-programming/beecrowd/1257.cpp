#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

int sthash(const string& s, int p) {
    int res = 0;

    for (size_t i = 0; i < s.length(); i++) {
        res += (s[i] - 'A') + p + i;
    }

    return res;
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        int s = 0;

        for (int j = 0; j < L; j++) {
            string st; cin >> st;
            s += sthash(st, j);
        }
        
        cout << s << endl;
    }

    return 0;
}
