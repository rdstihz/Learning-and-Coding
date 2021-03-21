n, m = map(int, input().split())

A = []
for i in range(m):
    A.append(int(input()))

D = []
for i in range(n):
    D.append(list(map(int, input().split())))

for k in range(n):
    for i in range(n):
        for j in range(n):
            D[i][j] = min(D[i][j], D[i][k] + D[k][j])
ans = 0
for i in range(1, m):
    ans += D[A[i - 1] - 1][A[i] - 1]
print(ans)
