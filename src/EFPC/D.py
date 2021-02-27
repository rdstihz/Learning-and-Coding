T = int(input())

for k in range(1, T + 1):
    line = input()
    S = 0
    for c in line:
        S = S + int(c)
    if S % 3 == 0:
        print("Case {}: Yes".format(k))
    else:
        print("Case {}: No".format(k))
