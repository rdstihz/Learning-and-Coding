
import sys
for n in sys.stdin:
    n = int(n)
    solve = False
    for a in range(1,n):
        for b in range(a,n):
            if a * a + b * b >= n:
                break
            for c in range(b,n):
                if a * a + b * b + c * c > n:
                    break
                elif a * a + b * b + c * c == n:
                    print("%d %d %d" % (a, b, c) )
                    solve = True
    if(not solve):
        print("No Solution")