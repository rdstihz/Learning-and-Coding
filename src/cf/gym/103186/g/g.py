#    Created by rdstihz at 2021-07-15 15:12:18

P = 998244353

n = int(input())
a = list(map(int, input().split()))
S = 1
cnt = 0
for x in a:
    if x % P == 0:
        cnt += 1
        continue
    S = S * x % P

if cnt == 0:
    for i in range(n):
        print(S * pow(a[i], P - 2, P) % P, end = " ")
elif cnt == 1:
    for i in range(n):
        if a[i] % P == 0:
            print(S, end = " ")
        else:
            print(0)
else:
    for i in range(n):
        print(0)