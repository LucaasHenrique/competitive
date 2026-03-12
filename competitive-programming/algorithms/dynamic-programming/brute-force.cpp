#include <cstdio>
#include <vector>
using namespace std;

int solve(vector<int> caminho, int n) {
    
    int atual = caminho.back(), ans = 0;

    if (atual + 1 <= n) {
        caminho.push_back(atual+1);
        ans += solve(caminho, n);
        caminho.pop_back();
    }

    if (atual + 2 <= n) {
        caminho.push_back(atual + 2);
        ans += solve(caminho, n);
        caminho.pop_back();
    }

    if (atual == n) ++ans;
    return ans;
}

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", solve({1}, n));
}
