#include <bits/stdc++.h>

using namespace std;

bool podeestar(int i, int P, int D) {
    return (i - P) % D == 0;
}

int main (int argc, char *argv[]) {
    
    int N, M, P, D;
    cin >> N >> M;

    int pos[M];
    int dis[M];

    int teste[N];

    for (int i = 0; i < M; i++) {
        cin >> P >> D;
        pos[i] = P;
        dis[i] = D;
    }
    
    for (int i = 0; i < N; i++) {
        teste[i] = 0;
        for (int j = 0; j < M; j++) {
            if (podeestar(i + 1, pos[j], dis[j])) {
                teste[i] = 1;
                break;
            } 
        }
    }

    for (int i = 0; i < N; i++) {
        cout << teste[i] << " ";
    }

    return 0;
}
