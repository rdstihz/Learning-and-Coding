T = int(input())

for k in range(1, T + 1):
    n = int(input())
    print("Case {}: {}".format(k, n * (n + 1) // 2 ))