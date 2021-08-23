#    Created by rdstihz at 2021-07-03 21:39:56

T = int(input())
P = 1000000007

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

for k in range(T):
    n = int(input())

    ans = 0

    i = 2
    lcm = 1

    while n:
        d = gcd(lcm, i)
        lcm = lcm // d * i
        
    

        t = n * d // i

        ans += (n - t) * i
        ans %= P
        n = t
        i += 1

    
    print(ans)