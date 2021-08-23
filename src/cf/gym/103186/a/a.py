#    Created by rdstihz at 2021-07-15 15:10:43

x1, y1, z1 = map(int, input().split())
x2, y2, z2 = map(int, input().split())

print(y1 * z2 - y2 * z1, z1 * x2 - z2 * x1, x1 * y2 - x2 * y1)