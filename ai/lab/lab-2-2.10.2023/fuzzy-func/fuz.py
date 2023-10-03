import numpy as np
import matplotlib.pyplot as plt
import skfuzzy as fuzz
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score


def real_y(x):
    return np.cos(x / 2) + np.sin(x / 3)


def real_z(x, y):
    return 0.5 * np.sin(x + y) * np.cos(y)


dots_n = 100

min_x = 0
max_x = 40

min_y = -2.5
max_y = 2.5

min_z = -1
max_z = 1

lams = 16

x_values = np.linspace(min_x, max_x, dots_n)
y_values = real_y(x_values)
z_values = real_z(x_values, y_values)


def means(min_v, max_v, n, i):
    return min_v + (max_v - min_v) / n * i


def add_lambdas(min_v, max_v, n):
    lambdas = []
    for i in range(n):
        current_mean = means(min_v, max_v, n, i)
        # lam = lambda val, current_mean=current_mean: fuzz.membership.gaussmf(val, current_mean, (max_v - min_v) / n / 2)
        # lam = lambda val, current_mean=current_mean: fuzz.membership.gbellmf(val, (max_v - min_v) / n / 2, 5,
        #                                                                      current_mean)
        lam = lambda val, current_mean=current_mean: fuzz.membership.gaussmf(val, current_mean, (max_v - min_v) / n / 6)

        lambdas.append(lam)

    return lambdas


x_lams = add_lambdas(min_x, max_x, lams)
y_lams = add_lambdas(min_y, max_y, lams)
z_lams = add_lambdas(min_z, max_z, lams)

for lam in x_lams:
    plt.plot(x_values, lam(x_values))

plt.show()


def choose_lam(value, lams):
    best_index = None
    best_score = float(0)

    for index, lam in enumerate(lams):
        score = lam(value)

        if score > best_score:
            best_score = score
            best_index = index

    return best_index


def to_fuzzy(values, lams):
    fuzzy_indexes = [choose_lam(value, lams) for value in values]
    return np.array(fuzzy_indexes)


def from_fuzz(value, min_v, max_v, n):
    return min_v + (max_v - min_v) / n * value


rules = {}

for i in range(lams):
    for j in range(lams):
        current_x = from_fuzz(i, min_x, max_x, lams)
        current_y = from_fuzz(j, min_y, max_y, lams)
        current_z = real_z(current_x, current_y)
        fuzzy_z = choose_lam(current_z, z_lams)

        rules[(i, j)] = fuzzy_z


def fuzzy_z(x, y):
    x_fuzz = choose_lam(x, x_lams)
    y_fuzz = choose_lam(y, y_lams)

    z_fuzz = rules[(x_fuzz, y_fuzz)]
    return from_fuzz(z_fuzz, min_z, max_z, lams)


def z_x(x_arr):
    z = []
    for x in x_arr:
        y = real_y(x)
        z.append(fuzzy_z(x, y))
    return z


my_zed = z_x(x_values)
plt.plot(x_values, my_zed)
plt.plot(x_values, y_values)
plt.plot(x_values, z_values)
plt.show()

mse = mean_squared_error(z_values, my_zed)
mae = mean_absolute_error(z_values, my_zed)
r2 = r2_score(z_values, my_zed)

# Print the error metrics
print(f"Mean Squared Error (MSE): {mse}")
print(f"Mean Absolute Error (MAE): {mae}")
print(f"R-squared (R2) Score: {r2}")
