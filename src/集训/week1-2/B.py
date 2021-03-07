m = int(input())
n = int(input())

a = []

for i in range(n):
    a.append(int(input()))

f = []
for i in range(0, m + 1):
    f.append(False)
f[0] = True
for i in range(n):
    for j in range(m, a[i] - 1, -1):
        f[j] |= f[j - a[i]]

bm = m
while not f[m]:
    m = m - 1
print(bm - m)
