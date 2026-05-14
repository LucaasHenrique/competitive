# MEX (Minimun Excluded)

-> MEX encontra o menor numero inteiro não negativo que não está no conjunto A;

$A = {2, 3, 0, 4, 5}$
$MEX(A) = 1;$

O MEX sempre procura pelo menor numero inteiro que não aparece no conjunto, ou seja, a busca sempre começa pelo 0.

então, se $a = [2, 2, 3, 4]$ e faço o $MEX(a)$, tenho como resultado $MEX = 0$;

-> The following algorithm runs in  O(NlogN)  time.
```c++
int mex(vector<int> const& A) {
    set<int> b(A.begin(), A.end());

    int result = 0;
    while (b.count(result))
        ++result;
    return result;
}
```

-> in $O(N)$
```c++
int mex(vector<int> const& A) {
    static bool used[MAX_N+1] = { 0 };

    // mark the given numbers
    for (int x : A) {
        if (x <= MAX_N)
            used[x] = true;
    }

    // find the mex
    int result = 0;
    while (used[result])
        ++result;

    // clear the array again
    for (int x : A) {
        if (x <= MAX_N)
            used[x] = false;
    }

    return result;
}
```

MEX with array updates
```c++
class Mex {
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(vector<int> const& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() {
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
```
***

