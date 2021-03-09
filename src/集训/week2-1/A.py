n = int(input())

N = n
n *= 2

f = []
g = []
for i in range(n + 1):
    f.append([])
    g.append([])
    for j in range(n + 1):
        f[i].append(0)
        g[i].append(1000000000)
a = [0]
t = list(map(int, input().split()))
a.extend(t)
a.extend(t)


for i in range(1, n + 1):
    a[i] += a[i - 1]
#print(a)
for l in range(n, 0, -1):
    f[l][l] = 0
    g[l][l] = 0
    for r in range(l + 1, n + 1):
        if r - l > N:
            break
        for k in range(l, r):
            f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + a[r] - a[l - 1])
            g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + a[r] - a[l - 1])


minv = 1000000000
maxv = 0
for i in range(1, N + 1):
    minv = min(minv, g[i][i + N - 1])
    maxv = max(maxv, f[i][i + N - 1])
print(minv)
print(maxv)
