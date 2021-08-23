#    Created by rdstihz at 2021-07-03 21:05:28

T = int(input())

for k in range(T):
    n = int(input())
    a = map(int ,input().split())

    A = 0
    B = 0

    for i in a:
        if i % 2 == 1:
            A += 1
        else:
            B += 1
    
    if A == B:
        print("Yes")
    else:
        print("No")