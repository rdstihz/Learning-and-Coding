n, m = map(int, input().split())

flag = [False] * (m + 1)
prime = []
for i in range(2, m + 1):
    if not flag[i]:
        prime.append(i)

    for t in prime:
        if i * t > m:
            break
        flag[i * t] = True
        if i % t == 0:
            break

cnt = [0,0]
for i in range(2, m + 1):
    cnt.append(cnt[-1] + (not flag[i]))

for k in range(n):
    l, r = map(int,input().split())
    if(l < 1 or r > m):
        print("Crossing the line")
        continue
    print(cnt[r] - cnt[l - 1])

