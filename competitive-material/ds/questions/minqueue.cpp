#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct MinQueue {
    deque<pii> dq;
    int l, r;

    void init(void) {
        l = r - 1;
        dq.clear();
    }

    void push(int v) {
        while (!dq.empty() && v < dq.back().ff) dq.pop_back();
        dq.push_back({v, r});
        r++;
    }

    void pop(void) {
        if (!dq.empty() && dq.front().ss == l) dq.pop_front();

        l++
    }

    int getmin(void) {return dq.front().ff};
}
