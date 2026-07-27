# Knapsack
***

Given a list of weights [w1,w2,...,wn], determine all sums that can be constructed using the weights.
For example, if the weights are [1,3,3,5], the following sums are possible

```c++
possible[0][0] = true;

for (int k = 1; k <= n; k++) {
    for (int x = 0; x <= W; x++) {
        if (x - w[k] >= 0) possible[x][k] |= possible[x-w[k]][k-1];
        possible[x][k] |= possible[x][k-1];
    }
}
```

```c++
possible[0] = true;
for (int k = 1; k <= n; k++) {
    for (int x = W; x >= 0; x--) {
        if (possible[x]) possible[x+w[k]] = true;
    }
}
```
