# 2. x ^ 2 + 2 * ln(y) = 1 and ln(x + e - 1) + y ^ 2 = 2, 0 <= x <= 2 and 0 <= y <= 2, (x, y) = ?
# f(x, y) = |x ^ 2 + 2 * ln(y) - 1| + |ln(x + e - 1) + y ^ 2 - 2|, 0 <= x, y <= 2
import random
import math
N = 100000
min_x = 0
min_y = 0
min_ans = 10000
for i in range(0, N) : 
    x = random.uniform(0, 2)
    y = (2 - math.log(x + math.e - 1)) ** 0.5
    ans = abs(x ** 2 + 2 * math.log(y) - 1) + abs(math.log(x + math.e - 1) + y ** 2 - 2)
    if ans < min_ans :
        min_ans = ans
        min_x = x
        min_y = y
        i = 0
print("x : {:.6f}\ny : {:.6f}\nans: {:.6f}".format(min_x, min_y, min_ans))