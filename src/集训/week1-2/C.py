m, n = map(int, input().split())

a = [0] * (n + 1)
b = [0] * (n + 1)

for i in range(1, n + 1):
    a[i], b[i] = map(int, input().split())

f = [[]]
for i in range(0, m + 1):
    f[0].append(0)
for i in range(1, n + 1):
    f.append([])

    for j in range(0, m + 1):
        f[i].append(f[i - 1][j])
        if j >= a[i]:
            f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + a[i] * b[i])


# print(f)


print(f[n][m])
