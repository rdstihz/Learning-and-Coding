#    Created by rdstihz at 2021-07-02 20:15:33

T = int(input())

for k in range(T):
    n = int(input())

    if n % 2 == 0:
        for i in range(1, n + 1, 2):
            print(i + 1, i, end = " ")
    else:
        print("3 1 2 ")
        for i in range(4, n + 1, 2):
            print(i + 1, i, end = " ")
    
    print()