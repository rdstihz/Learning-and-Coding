def exgcd(a, b):
    if b == 0:
        return 1, 0, a
    else:
        y, x, d = exgcd(b, a % b)
        y -= x * (a // b)
        return x, y, d


a = []
m = []
n = int(input())

for i in range(n):
    M, A = map(int, input().split())
    a.append(A)
    m.append(M)

lcm = 1
x = 0
solvavle = True
for i in range(n):
    t, y, d = exgcd(lcm, m[i])
    if (a[i] - x) % d != 0:
        solvavle = False
        break
    t = t * (a[i] - x) // d
    x = x + t * lcm
    t, y, d = exgcd(lcm, m[i])
    lcm = lcm * m[i] // d
if solvavle:
    x = (x % lcm + lcm) % lcm
    print(x)
else:
    print(-1)
