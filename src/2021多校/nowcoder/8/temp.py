from math import *

def pow_mod(a, b, p):
    res = 1
    while b:
        if b & 1:
            res = res * a % p 
        b >>= 1
        a = a * a % p
    return res


P = 4933

for i in range(100):
    for j in range(100):
        if i * pow_mod(j, P-2, P) % P == 4523:
            print(i, j)
            #exit()
