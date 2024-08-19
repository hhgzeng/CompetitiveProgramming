# z = x ^ 2 + 2 * y ^ 2 - x, x ^ 2 + y ^ 2 <= 1, y >= 0, max(z) = ?
# ans(x, y) = (-1 / 2, sqrt(3) / 2)
import random
import math
N = 100000
# 方法一
# max_x = 0
# max_y = 0
# max_ans = -1
# for i in range(0, N) : 
#     x = random.uniform(-1, 1)
#     y = random.uniform(0, 1)
#     if x ** 2 + y ** 2 > 1 :
#         continue
#     ans = x ** 2 + 2 * y ** 2 - x
#     if ans > max_ans :
#         max_ans = ans
#         max_x = x
#         max_y = y
#         i = 0
# print("x : {:.6f}\ny : {:.6f}\nans: {:.6f}".format(max_x, max_y, max_ans))

# 方法二
max_x = 0
max_y = 0
max_ans = -1
for i in range(0, N) :
    r = random.uniform(0, 1)
    c = random.uniform(0, math.pi)
    x = r * math.cos(c)
    y = r * math.sin(c)
    ans = x ** 2 + 2 * y ** 2 - x
    if ans > max_ans :
        max_ans = ans
        max_x = x
        max_y = y
        i = 0
print("x : {:.6f}\ny : {:.6f}\nans: {:.6f}".format(max_x, max_y, max_ans))