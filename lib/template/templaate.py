import sys

# Otimização de I/O (Equivalente ao ios::sync_with_stdio(0); cin.tie(0);)
input = lambda: sys.stdin.readline().rstrip("\r\n")

def print(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)

# Constantes (Valores equivalentes ao C++)
INF64 = 1 << 60
INF32 = 1 << 30
MAXN = 300100

# Atalhos úteis para leitura de dados
def input_int(): return int(input())
def input_list(): return list(map(int, input().split()))


def solve():
    # Sua solução aqui
    pass


def main():
    # Casos de teste (basta desentalar a leitura se o problema tiver múltiplos casos)
    t = 1
    # t = input_int()
    
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
