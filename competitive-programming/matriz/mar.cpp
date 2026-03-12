#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int x1A = 1, x2A = 1, y1A = 3, y2A = 3, x1B = 2, x2B = 2, y1B = 4, y2B = 4;
    

    int x = max(0, min(x2A, x2B) - max(x1A, x1B));
    int y = max(0, min(y2A, y2B) - max(y1A, y1B));

    int area = x * y;

    cout << area;
    

    return 0;
}
