n, m, t = map(int, input().split())

w = [[]]
inf = 100000000
for i in range(1, n + 1):
    w.append([inf])
    for j in range(1, n + 1):
        w[i].append(inf)

for i in range(m):
    a, b, c = map(int, input().split())
    w[a][b] = c

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            w[i][j] = min(w[i][j], max(w[i][k], w[k][j]))
for i in range(t):
    a, b = map(int, input().split())
    if(w[a][b] == inf):
        print(-1)
    else:
        print(w[a][b])
