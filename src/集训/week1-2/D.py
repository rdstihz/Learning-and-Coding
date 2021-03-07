n, m = map(int, input().split())


a =list(map(int, input().split())) 

f = []
for i in range(0, n + 1):
    f.append([])
    for j in range(0, m + 1):
        f[i].append(0)

f[0][0] = 1
for i in range(1, n + 1):
    for j in range(0, m + 1):
        f[i][j] = f[i - 1][j]
        if j >= a[i - 1]:
            f[i][j] += f[i - 1][j - a[i - 1]]

print(f[n][m])

