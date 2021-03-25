

import sys


def f(n, p, pk):
    if n == 0:
        return 1
    res = f(n // p, p, pk)

    global T

    res = res * pow(T, n // pk, pk) % pk

    for i in range((n // pk) * pk + 1, n + 1):
        if i % p != 0:
            res = res * i % pk
    return res


def g(n, p):
    if n == 0:
        return 0
    else:
        return g(n // p, p) + n // p


def exgcd(a, b):
    if b == 0:
        return 1, 0, a
    else:
        y, x, d = exgcd(b, a % b)
        y -= a // b * x
        return x, y, d


def inv(a, b):
    x, y, d = exgcd(a, b)
    return (x % b + b) % b



n, m, P = map(int, input().split())
# 将P分解质因数
primes = []
alphas = []

i = 2
P2 = P
while i * i <= P:
    if P % i == 0:
        primes.append(i)
        alphas.append(0)
        while P % i == 0:
            P //= i
            alphas[-1] += 1
    i += 1
if P > 1:
    primes.append(P)
    alphas.append(1)
P = P2

a = []
b = []

for i in range(len(primes)):
    a.append(0)
    b.append(primes[i] ** alphas[i])
    T = 1
    p = primes[i]
    pk = b[i]
    for j in range(1, pk + 1):
        if j % p != 0:
            T = T * j % pk

    a[i] = f(n, p, pk) * (inv(f(m, p, pk), pk) * inv(f(n - m, p, pk), pk) % pk ) % pk
    a[i] = a[i] * pow(p, g(n, p) - g(m, p) - g(n - m, p), pk) % pk

ans = 0
for i in range(len(primes)):
    Mi = P // b[i]
    ans += a[i] * Mi * inv(Mi, b[i])
    ans %= P
print(ans)

