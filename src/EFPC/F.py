T = int(input())

for k in range(1, T + 1):
    n = int(input())
    s = list(map(ord, input()))
    s.sort()
    mid = s[(n + 1) // 2]

    ans = 0

    for x in s:
        ans += abs(x - mid)

    print("Case {}: {}".format(k,ans))
