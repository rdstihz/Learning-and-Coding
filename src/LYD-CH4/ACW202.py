def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def pow_mod(a, b, p):
    res = 1
    while b > 0:
        if b & 1:
            res = (res * a) % p
        a = (a * a) % p
        b >>= 1
    return res % p


def get_phi(n):
    res = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            res = res // i * (i - 1)
            while n % i == 0:
                n //= i
        i = i + 1
    if n > 1:
        res = res // n * (n - 1)
    return res



l = int(input())
T = 0
while l != 0:

    T = T + 1
    l = 9 * l // gcd(l, 8)
    p = get_phi(l)
    ans = p + 1
    i = 1
    while i * i < p:
        if p % i == 0:
            if pow_mod(10, i, l) == 1:
                ans = min(ans, i)
            if pow_mod(10, p // i, l) == 1:
                ans = min(ans, p / i)
        i = i + 1
    if ans > p:
        ans = 0
    print("Case %d: %d" % (T, ans))
    l = int(input())
