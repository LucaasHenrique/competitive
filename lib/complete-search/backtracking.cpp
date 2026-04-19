#include <iostream>
#include <vector>

using std::cout;

int n;
int count = 0;

bool column[100];
bool diag1[200]; // x + y
bool diag2[200]; // x - y + (n - 1)
int pos[100];

void printBoard() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (pos[y] == x) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void search(int y) {
    if (y == n) {
        count++;
        //printBoard();
        return;
    }

    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x + y] || diag2[x-y+n-1]) continue;
        pos[y] = x;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }   
}

int32_t main () {
    
    n = 12;
    
    search(0);

    cout << count << "\n";
    return 0;
}
