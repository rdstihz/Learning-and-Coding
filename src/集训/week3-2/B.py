
def sort(l, r):
    if l == r:
        return
    global a
    global b
    global cnt
    m = (l + r) // 2
    sort(l, m)
    sort(m + 1, r)

    i = l
    j = m + 1
    k = l

    while i <= m and j <= r:
        if a[i] < a[j]:
            b[k] = a[i]
            i += 1
            k += 1
        else:
            b[k] = a[j]
            j += 1
            k += 1
            cnt += m - i + 1
    while i <= m:
        b[k] = a[i]
        k += 1
        i += 1
    while j <= r:
        b[k] = a[j]
        k += 1
        j += 1

    a[l:r + 1] = b[l : r + 1]


import sys
n = int(input())
a = []

for line in sys.stdin:
    t = map(int,line.split())
    a.extend(t)


b = a.copy()
cnt = 0


sort(0, n - 1)

print(cnt)