
from math import sqrt

T = int(input())

for k in range(1, T + 1):
    n = int(input())
    m = int(sqrt(n))

    while n % m != 0:
        m = m - 1
    ans = m + n // m
    print("Case {0}: {1}".format(k, ans))
