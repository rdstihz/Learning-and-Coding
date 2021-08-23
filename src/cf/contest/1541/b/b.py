#    Created by rdstihz at 2021-07-02 20:20:52

T = int(input())

for k in range(T):
    n = int(input())
    a = [0]
    a.extend(map(int, input().split()))
    ans = 0
    for i in range(1, n + 1):
        st = ((a[i] - i) % a[i] + a[i]) % a[i]
        for j in range(st, i, a[i]):
            if i + j == a[i] * a[j]:
                ans += 1
    print(ans)

