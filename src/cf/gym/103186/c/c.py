#    Created by rdstihz at 2021-07-15 16:33:09
from math import ceil

n, m = map(int, input().split())
s = [0] * (n + 1)
for i in range(n):
    a, b = map(int, input().split())
    s[a] = b

avg = ceil(sum(s) / n)

for i in range(1, n + 1):
    if i == m:
        s[i] = max(s[i], 60)
    elif s[i] >= avg:
        s[i] = max(0, s[i] - 2)

for x in s[1:]:
    print(x, end = " ")