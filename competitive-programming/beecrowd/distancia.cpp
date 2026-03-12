#include <bits/stdc++.h>
 
using namespace std;

int main() {
 
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    double d = (double) sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    
    cout << fixed << setprecision(4);
    cout << d << endl;
    return 0;
}
