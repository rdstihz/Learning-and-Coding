T = int(input())

for k in range(1, T + 1):
    n = int(input())
    s = list(map(ord, input()))
    ans = 100000000000

    for t in range(ord('a'), ord('z') + 1):
        cur = 0
        for c in s:
            cur += abs(t - c)
        ans = min(ans, cur)
    print("Case {}: {}".format(k,ans))
