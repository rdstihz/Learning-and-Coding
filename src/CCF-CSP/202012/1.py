n = int(input())

ans = 0
for i in range(n):
    a,b = map(int, input().split())
    ans += a * b
if ans < 0:
    print(0)
else:
    print(ans)
    