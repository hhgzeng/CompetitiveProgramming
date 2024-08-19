import random
# f(x) = 2 * x ^ 3 - 3 * x ^ 2, -1 <= x <= 4, min = ?
N = 50000
min_x = 100
min_y = 1000
for i in range(0, N) : 
    x = random.uniform(-1, 4)
    y = 2 * x ** 3 - 3 * x ** 2
    if y < min_y :
        min_y = y
        min_x = x
        i = 0
print("x : {:.3f}\ny : {:.3f}".format(min_x, min_y))