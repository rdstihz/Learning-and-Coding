import numpy as np


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


n, m = map(int, input().split())
b = gcd(n, m)


f = np.array([0, 1])

p = np.array([[0, 1], [1, 1]])

while b:
    if b & 1:
        f = np.dot(f, p)
    p = np.dot(p, p)
    b >>= 1
P = 100000000
print(f[0] % P)
