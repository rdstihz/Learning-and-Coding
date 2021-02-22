
def work(n, w):
    x = (n - 1) // w + 1
    y = n - w * (x - 1)

    if x % 2 == 1:
        return x,y
    else:
        return x,(w - y + 1)

import sys

for line in sys.stdin:


    w, n, m = map(int, line.split())

    x1,y1 = work(n,w)
    x2,y2 = work(m,w)

    print(abs(x1 - x2) + abs(y1 - y2))


