# loj 143
import sys
T = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]


def isprime(n):
    if n == 1:
        return False
    global T
    for a in T:
        if a >= n:
            break

        x = n - 1
        tmp = pow(a, x, n)
        if tmp != 1:
            return False
        
        while x % 2 == 0 and tmp == 1:
            x //= 2
            tmp = pow(a, x, n)
            if tmp != 1 and tmp != n - 1:
                return False
    return True


for line in sys.stdin:
    n = int(line)
    if isprime(n):
        print("Y")
    else:
        print("N")
