import math
# f(x) = ln(x) + x, x > 0, f(x) = 2
# ln(x) + x = 2
l = 1
r = 2

while l < r : 
    x = (l + r) / 2
    if math.log(x) + x == 2 :
        print(round(x, 3))
        break
    if math.log(x) + x > 2 :
        r = x
    else :
        l = x