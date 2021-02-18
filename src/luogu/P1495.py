
def exgcd(a, b, x, y):
    if b == 0:
        x[0] = 1
        y[0] = 0
        return a
    else:
        d = exgcd(b, a % b, y, x)
        y[0] -= x[0] * (a // b)
        return d


n = int(input())

a = []
m = []
pm = 1
for i in range(n):
    A, B = map(int, input().split())
    a.append(B)
    m.append(A)
    pm = pm * A


ans = 0
x = [0]
y = [0]



for i in range(n):
    exgcd(pm // m[i], m[i], x, y)
    t = (x[0] % m[i] + m[i]) % m[i]
    ans += a[i] * (pm // m[i]) * t
ans = (ans % pm + pm) % pm
print(ans)
