# 1. 2 ^ x = x ^ 2, x < 0, 近似值 -> f(x) = |2 ^ x - x ^ 2|, min(f(x)), x < 0
import random
N = 100000
min_x = 0
min_y = 100
for i in range(0, N) : 
    x = random.uniform(-1, 0)
    y = abs(2 ** x - x ** 2)
    if y < min_y :
        min_y = y
        min_x = x
        i = 0
print("x : {:.5f}\ny : {:.5f}".format(min_x, min_y))