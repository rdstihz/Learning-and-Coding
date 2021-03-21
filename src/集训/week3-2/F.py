from math import sqrt

l, r = map(int, input().split())
n = r - l + 1
flag = [False] * n
t = int(sqrt(r))


for i in range(2, t + 1):
    start = max(2, (l - 1) // i + 1) * i
    for j in range(start, r + 1, i):
        flag[j - l] = True
cnt = 0
for isprime in flag:
    cnt += not isprime

print(cnt)