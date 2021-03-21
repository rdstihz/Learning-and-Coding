n = int(input())

prod = [1]
for i in range(1, n + 1):
    prod.append(prod[i - 1] * i)


C = [[1,0]]

for i in range(1, n + 1):
    C.append([1])
    for j in range(1, i + 1):
        C[i].append(C[i - 1][j - 1] + C[i - 1][j])
    C[i].append(0)

ans = 0
p = 1

for i in range(0,n + 1):
    ans += p * prod[n - i] * C[n][i]
    p *= -1

print(ans)
