#    Created by rdstihz at 2021-07-15 16:42:35

n, k = map(int, input().split())
ans = 0

M = {"D": 16, "C": 24, "B": 54, "A": 80, "S": 10000}

for i in range(n):
    t, p = input().split()
    p = float(p)
    ans += M.get(t) * p
ans *= k
ans -= k * 23
print(ans)
