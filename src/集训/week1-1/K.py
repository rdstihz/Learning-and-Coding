import numpy as np

b = int(input())

f = np.array([0, 1])

p = np.array([[0, 1], [1, 1]])

while b:
    if b & 1:
        f = np.dot(f, p)
    p = np.dot(p,p)
    b >>= 1
P = 1000000007
print(f[0] % P)
