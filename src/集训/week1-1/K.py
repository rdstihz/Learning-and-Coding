import numpy as np
P = 1000000007

b = int(input())

f = np.array([0, 1])

p = np.array([[0, 1], [1, 1]])

while b:
    if b & 1:
        f = np.dot(f, p)
        f = np.mod(f, P)
    p = np.dot(p, p)
    p = np.mod(p, P)
    b >>= 1

print(f[0] % P)
