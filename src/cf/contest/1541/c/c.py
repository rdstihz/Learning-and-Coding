#    Created by rdstihz at 2021-07-02 20:28:28

T = int(input())

for k in range(T):
    n = int(input())
    d = list(map(int, input().split()))
    d.sort()
    #print(d)
    S = d[:]
    for i in range(1, n):
        S[i] += S[i - 1]
    
    ans = d[-1]

    for i in range(1, n):
        ans += S[i - 1] - i * d[i]
    print(ans)