P = 9901


def pow_mod(a, b, p):
    res = 1
    while b:
        if b & 1:
            res = (res * a) % p
        a = (a * a) % p
        b >>= 1
    return res % p


s = input().split()
a = int(s[0])
b = int(s[1])

# 将a分解质因数
p = []
c = []

i = 2
while i * i <= a:
    if a % i == 0:
        p.append(i)
        c.append(0)
        while a % i == 0:
            c[-1] = c[-1] + 1
            a //= i
    i = i + 1
if a > 1:
    p.append(a)
    c.append(1)


ans = 1
l = len(p)
for i in range(l):
    if (p[i] - 1) % P == 0:
        ans = (ans * (c[i] * b + 1)) % P
    else:
        ans = ans * (pow_mod(p[i], c[i] * b + 1, P) - 1) * \
            pow_mod(p[i] - 1, P - 2, P) % P
print(ans)
