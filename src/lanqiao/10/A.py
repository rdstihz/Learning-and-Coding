

def check(x):
    while(x):
        t = x % 10
        if t == 2 or t == 0 or t == 1 or t == 9:
            return True
        x //= 10
    return False

res = 0
for i in range(1, 2020) :
    if check(i):
        res += i ** 2

print(res)
