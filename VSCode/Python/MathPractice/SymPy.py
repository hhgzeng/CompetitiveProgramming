from sympy import *

x = symbols('x')
y = Function('y')(x)  # 定义 y 为关于 x 的函数

# 定义微分方程
eq = Eq(y.diff(x, 2) + 4 * y.diff(x, 1) + 29 * y, 0)

# 定义初始条件，假设当 x = 0 时，y = 1
ics = {y.subs(x, 0): 3, y.diff(x, 1).subs(x, 0): 5}

# 求解微分方程
solution = dsolve(eq, ics = ics)
print(solution)
exit()

expr = x ** 2 + y ** 2
der = integrate(expr, x) # integrating: 积分
print(der)
der = diff(expr, x)      # differentiation: 导数
print(der)

# solve函数求方程解 solve equation
print(solve([x + y - 3, 2 * x - y - 1], [x, y]))