T = int(input())

for k in range(1, T + 1):
    N, a, b = map(int, input().split())

    ans = ()
    maxv = 0

    for i in range(N):
        x, y, z = map(int, input().split())

        if y % 2 == 1 or y > 2 * (x + 1):
            continue
        M = 12 * x + y + 16 * z
        if (x * a + y * b / 2) / M > maxv:
            maxv = (x * a + y * b / 2 ) / M
            ans = (x, y, z)

    print("Case {}: ".format(k), end = '')
    x, y, z = ans
    if x:
        print('C', end='')
        if x > 1:
            print(x, end='')

    if y:
        print('H', end='')
        if y > 1:
            print(y, end='')

    if z:
        print('O', end='')
        if z > 1:
            print(z, end='')
    print()
