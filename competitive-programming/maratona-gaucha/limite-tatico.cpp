#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> tribos(N);
    for (int i = 0; i < N; ++i) {
       cin >> tribos[i];
    }
    sort(tribos.begin(), tribos.end());
    long long mensoma = LLONG_MAX;
    bool encontrou = false;
    int maxTribo = tribos.back();
    if (tribos[N - 1] > tribos[N - 2]) {
        mensoma = tribos[N - 1];
        encontrou = true;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long soma_atual= (long long)tribos[i] + tribos[j];
            if (soma_atual> maxTribo) {
                mensoma = min(mensoma, soma_atual);
                encontrou = true;
                break;
            }
        }
    }
    if (encontrou?cout << mensoma << "\n": cout<<-1<< "\n")

    return 0;
}
