import statistics

import skfuzzy as fuzz
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score


def real_y(x):
    return np.cos(x / 2) + np.sin(x / 3)


def real_z(x, y):
    return 0.5 * np.sin(x + y) * np.cos(y)


max_x = 40

x = np.linspace(0, max_x, 1000)

y = real_y(x)
z = real_z(x, y)

input_n = 12
output_n = 16

input_x_sets = []

for i in range(input_n):
    gaus = lambda inp, i=i: fuzz.membership.gaussmf(inp, max_x / input_n * i, max_x / input_n / 2)

    # gaus = lambda inp, i=i: fuzz.membership.gbellmf(inp, max_x / input_n / 2, 5, max_x / input_n * i)
    input_x_sets.append(gaus)

min_y = -2
max_y = 2

input_y_sets = []

for i in range(input_n):
    gaus = lambda inp, i=i: fuzz.membership.gaussmf(inp, min_y + (max_y - min_y) / input_n * i,
                                                    (max_y - min_y) / input_n / 2)

    # gaus = lambda inp, i=i: fuzz.membership.gbellmf(inp, (max_y - min_y) / input_n / 2, 5,
    #                                                 min_y + (max_y - min_y) / input_n * i)
    input_y_sets.append(gaus)

min_z = -0.7
max_z = 0.7

output_sets = []

for i in range(output_n):
    gaus = lambda inp, i=i: fuzz.membership.gaussmf(inp, min_z + (max_z - min_z) / output_n * i,
                                                    (max_z - min_z) / output_n / 2)

    # gaus = lambda inp, i=i: fuzz.membership.gbellmf(inp, (max_z - min_z) / output_n / 2, 5,
    #                                                 min_z + (max_z - min_z) / output_n * i)
    output_sets.append(gaus)


def set_n_x(variable):
    def find_highest_index(value):
        results = [gaus(value) for gaus in input_x_sets]
        highest_index = np.argmax(results)
        return highest_index

    # If variable is a single float or ndarray
    if isinstance(variable, (float, np.ndarray)):
        if isinstance(variable, float):
            return find_highest_index(variable)
        elif isinstance(variable, np.ndarray):
            return [find_highest_index(val) for val in variable]

    # If variable is a list
    elif isinstance(variable, list):
        return [find_highest_index(val) for val in variable]


def set_n_y(variable):
    def find_highest_index(value):
        results = [gaus(value) for gaus in input_y_sets]
        highest_index = np.argmax(results)
        return highest_index

    # If variable is a single float or ndarray
    if isinstance(variable, (float, np.ndarray)):
        if isinstance(variable, float):
            return find_highest_index(variable)
        elif isinstance(variable, np.ndarray):
            return [find_highest_index(val) for val in variable]

    # If variable is a list
    elif isinstance(variable, list):
        return [find_highest_index(val) for val in variable]


def set_n_z(variable):
    def find_highest_index(value):
        results = [gaus(value) for gaus in output_sets]
        highest_index = np.argmax(results)
        return highest_index

    # If variable is a single float or ndarray
    if isinstance(variable, (float, np.ndarray)):
        if isinstance(variable, float):
            return find_highest_index(variable)
        elif isinstance(variable, np.ndarray):
            return [find_highest_index(val) for val in variable]

    # If variable is a list
    elif isinstance(variable, list):
        return [find_highest_index(val) for val in variable]


rules = []

possible_y = np.linspace(min_y, max_y, 100)

for x_val in x:
    for y_val in possible_y:
        z_val = real_z(x_val, y_val)

        x_set = set_n_x(x_val)
        y_set = set_n_y(y_val)
        z_set = set_n_z(z_val)

        rules.append((x_set, y_set, z_set))

rules = set(rules)


def set_to_real(index):
    output_nf = float(output_n)

    if isinstance(index, (float, int)):
        index = float(index)  # Cast to float if it's an int

        # Perform the calculation for a single value
        return min_z + (max_z - min_z) / output_nf * index

        # Check if index is a list
    elif isinstance(index, list):
        # Perform the calculation for each value in the list
        return [min_z + (max_z - min_z) / output_nf * float(val) for val in index]


def almost_zed(x, y):
    x_set = set_n_x(x)
    y_set = set_n_y(y)
    z_set = []

    for i in range(len(x_set)):
        matching_rules = [(x_rule, y_rule, z_out) for (x_rule, y_rule, z_out) in rules if
                          x_rule == x_set[i] and y_rule == y_set[i]]
        z_values = [rule[2] for rule in matching_rules]
        most_common_z = statistics.mode(z_values)
        z_set.append(int(most_common_z))

    return set_to_real(z_set)


def x_z(x):
    return almost_zed(x, real_y(x))


x = np.linspace(0, max_x, 1000)

y = real_y(x)
z = real_z(x, y)
my_zeds = x_z(x)

plt.plot(x, y, 'r')
plt.plot(x, z, 'b')
plt.plot(x, my_zeds, 'g')
plt.grid()
plt.show()

# Calculate MAE
mae = mean_absolute_error(z, my_zeds)

# Calculate RMSE
rmse = np.sqrt(mean_squared_error(z, my_zeds))

# Calculate R-squared
r_squared = r2_score(z, my_zeds)

print(f"Mean Absolute Error (MAE): {mae}")
print(f"Root Mean Squared Error (RMSE): {rmse}")
print(f"R-squared (Coefficient of Determination): {r_squared}")
