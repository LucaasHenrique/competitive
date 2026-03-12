#include <bits/stdc++.h>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, M, tot = 0;
    cin >> N >> M;
    set<int> figus;
    
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        figus.insert(x);
    }

    cout << N - figus.size() << endl;

    return 0;
}
