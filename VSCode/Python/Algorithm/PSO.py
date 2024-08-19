import numpy as np
import matplotlib.pyplot as plt

# 适应度函数
def fun(x):
    return np.sum(x ** 2) + 25 * (np.sum(np.sin(x) ** 2))

# PSO 训练函数
def pso_train(T, N, D, c1, c2, Vmax, Vmin, Xmax, Xmin):
    # 初始化粒子位置和速度
    X = np.random.rand(N, D) * (Xmax - Xmin) - Xmax
    V = np.random.rand(N, D) * (Vmax - Vmin) - Vmax

    # 计算初始适应度
    fit = np.array([fun(X[i, :]) for i in range(N)])

    # 初始化个体极值和群体极值
    bestfitness = np.min(fit)
    bestindex = np.argmin(fit)
    zbest = X[bestindex, :]
    gbest = X
    fitnessgbest = fit
    fitnesszbest = bestfitness

    # 用于存储每次迭代的最优值
    yy = []

    # 迭代寻优
    for i in range(T):
        for j in range(N):
            # 速度更新
            V[j, :] = V[j, :] + c1 * np.random.rand() * (gbest[j, :] - X[j, :]) + c2 * np.random.rand() * (zbest - X[j, :])
            V[j, np.where(V[j, :] > Vmax)[0]] = Vmax
            V[j, np.where(V[j, :] < Vmin)[0]] = Vmin

            # 位置更新
            X[j, :] = X[j, :] + 0.5 * V[j, :]
            X[j, np.where(X[j, :] > Xmax)[0]] = Xmax
            X[j, np.where(X[j, :] < Xmin)[0]] = Xmin

            # 适应度更新o
            fit[j] = fun(X[j, :])

        for j in range(N):
            # 个体最优更新
            if fit[j] < fitnessgbest[j]:
                gbest[j, :] = X[j, :]
                fitnessgbest[j] = fit[j]

            # 群体最优更新
            if fit[j] < fitnesszbest:
                zbest = X[j, :]
                fitnesszbest = fit[j]

        yy.append(fitnesszbest)

    # 结果分析
    plt.plot(yy)
    plt.title("最优个体适应度")
    plt.xlabel("进化代数")
    plt.ylabel("适应度")
    plt.show()

    print(f"最优个体是：{zbest[0]}, {zbest[1]}")
    print(f"最小值是：{fun(zbest)}")

    return zbest, fitnesszbest

# 参数初始化
c1 = 1.5
c2 = 1.5
T = 100
N = 50
D = 2
Vmax = 1
Vmin = -1
Xmax = 3
Xmin = -3

# 执行 PSO 训练
zbest, fitnesszbest = pso_train(T, N, D, c1, c2, Vmax, Vmin, Xmax, Xmin)