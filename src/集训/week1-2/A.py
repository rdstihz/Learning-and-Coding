def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


n = int(input())
a = list(map(int, input().split()))

d = abs(a[0])

for i in range(1, n):
    d = gcd(d, abs(a[i]))

print(d)
