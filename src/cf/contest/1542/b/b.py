#    Created by rdstihz at 2021-07-03 21:12:08

T = int(input())

for k in range(T):
    n, a, b = map(int, input().split())

    t = 1
    ok = False
    
    if a == 1:
        if (n - 1) % b == 0:
            print("Yes")
        else:
            print("No")
        continue
    
    while t <= n:
        if (n - t) % b == 0:
            ok = True
            break
        t *= a


    if ok:
        print("Yes")
    else:
        print("No")