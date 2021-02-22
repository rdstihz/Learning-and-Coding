S = sum(range(1, 50))

for i in range(1, 49):
    for j in range(i + 2, 49):
        if S - i - i - 1 + i * (i + 1) - j - j - 1 + j * (j + 1) == 2015:
            if i != 10:
                print(i)
