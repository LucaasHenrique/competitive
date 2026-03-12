#include <bits/stdc++.h>
#include <iterator>

using namespace std;

int main (int argc, char *argv[]) {

    set<int> s;
    multiset<int> z;;

    z.insert(5);
    z.insert(5);
    z.insert(5);

    for (auto x: z) {
        cout << x << endl;
    }

    s.insert(5);
    s.insert(3);
    s.insert(1);

    cout << s.count(1) << endl;
    s.erase(3);

    for (auto x: s) {
        cout << x << endl;
    }

    return 0;
}
