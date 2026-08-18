import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")
def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)

INF64 = 1 << 60
INF32 = 1 << 30
MAXN = 300100

MOD = 1000000007

def input_int(): return int(input())
def input_list(): return list(map(int, input().split()))


def solve():
    n = input_int() 
    
    while (n > 0):
        a, b, c = input_list();

        res = pow(b, c, MOD-1)
        print(pow(a, res, MOD)) 
        n -= 1;

def main():
    t = 1
    
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
