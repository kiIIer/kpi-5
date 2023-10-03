import numpy as np
import matplotlib.pyplot as plt
import skfuzzy as fuzz


def real_y(x):
    return np.cos(x / 2) + np.sin(x / 3)


def real_z(x, y):
    return 0.5 * np.sin(x + y) * np.cos(y)


dots_n = 100

min_x = 0
max_x = 40

min_y = -2
max_y = 2

min_z = -0.5
max_z = 0.5

lams = 10

x_values = np.linspace(min_x, max_x, dots_n)
y_values = real_y(x_values)
z_values = real_z(x_values, y_values)


# plt.plot(x_values, y_values)
# plt.plot(x_values, z_values)
# plt.show()


def means(min_v, max_v, n, i):
    return min_v + (max_v - min_v) / n * i


def add_lambdas(min_v, max_v, n):
    lambdas = []
    for i in range(n):
        current_mean = means(min_v, max_v, n, i)
        lam = lambda val, current_mean=current_mean: fuzz.membership.gaussmf(val, current_mean, (max_v - min_v) / n / 2)
        lambdas.append(lam)

    return lambdas


x_lams = add_lambdas(min_x, max_x, lams)
y_lams = add_lambdas(min_y, max_y, lams)
z_lams = add_lambdas(min_z, max_z, lams)


def choose_lam(value, lams):
    best_index = None
    best_score = float(-1)

    for index, lam in enumerate(lams):
        score = lam(value)

        if score > best_score:
            best_score = score
            best_index = index

    return best_index
