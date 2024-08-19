import numpy as np
from scipy import linalg
from scipy.optimize import minimize
from scipy.integrate import quad

# inv
# matrix = np.array([[1, 2], [3, 4]])
# inverse_matrix = linalg.inv(matrix)
# print(inverse_matrix)
# result = np.dot(matrix, inverse_matrix)
# print(result)

# def objective(x):
#     return x ** 2 + 1 

# x0 = [0]
# result = minimize(objective, x0)
# print(result.x)

# 求矩阵线性方程解
# A = np.array([[1, 2], [3, 4]])
# det = linalg.det(A)
# print(det)

# B = np.array([5, 6])
# x = linalg.solve(A, B)
# print(x)

# 求f函数，x：0~1积分
def f(x):
    return x ** 2

result, error = quad(f, 0, 1)
print(result)