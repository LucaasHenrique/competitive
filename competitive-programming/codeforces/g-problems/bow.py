import sys 
s = str(input())

n = 1000

sys.set_int_max_str_digits(10000000)

def exp(a, b):
    if (b == 0): return 1

    t = exp(a, b//2)

    if (b%2 == 1):
        return a * t * t
    
    return t * t 

if s == '0':
    print(0)
    exit() 

t = 0;
for i in range(0, n):
    x = bin(exp(4, i))
    t += 1
    
    if (x[2:] == s):
        print(i)
        break
    
    if (len(x[2:]) > len(s)):
        print(t-1)
        break 
    
