
n = int(input())
m1, m2 = map(int, input().split())

flag = [False] * (m1 + 1)
prime = []
cm = []

for i in range(2, m1 + 1):
    if not flag[i]:
        prime.append(i)
    for j in prime:
        if i * j > m1:
            break

        flag[i * j] = True
        if i % j == 0:
            break
tot = len(prime)
for x in prime:
    cm.append(0)
    while m1 % x == 0:
        cm[-1] += 1
        m1 //= x
    cm[-1] *= m2
    
ans = 10000000
S = map(int, input().split())
for s in S:
    cs = []
    
    for x in prime:
        cs.append(0)
        while s % x == 0:
            cs[-1] += 1
            s //= x
        
    
    t = 0
    for i in range(tot):
        if cm[i] != 0 and cs[i] == 0:
            t = 10000000
            break
        if cm[i] != 0:
            t = max(t, (cm[i] - 1) // cs[i] + 1 )
    ans = min(ans, t)

if ans == 10000000:
    print(-1)
else:
    print(ans)
    