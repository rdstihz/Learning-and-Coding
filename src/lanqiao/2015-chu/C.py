
x = 1
while True:
    cnt = [0] * 10
    a = x * x
    b = a * x

    while a:
        cnt[a % 10] += 1
        a //= 10
    while b:
        cnt[b % 10] += 1
        b //= 10
    solve = True
    for i in cnt:
        if i != 1:
            solve = False
            break
    
    if solve:
        print(x)
        break
    x += 1
    

