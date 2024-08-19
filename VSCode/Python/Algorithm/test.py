import numpy as np

# 适应度函数
def fun(x):
    return np.sum(x ** 2) + 25 * (np.sum(np.sin(x) ** 2))

x = np.array([-0.0022800, -0.0000772])
print(fun(x))