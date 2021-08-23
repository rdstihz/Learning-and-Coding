#    Created by rdstihz at 2021-07-14 22:37:13

T = int(input())

for k in range(T):
    n = int(input())
    S = 0
    i = 1
    while S < n:
        S += 2 * i - 1
        i += 1
    print(i - 1)