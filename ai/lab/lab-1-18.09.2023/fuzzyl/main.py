import numpy as np
import matplotlib.pyplot as plt
import skfuzzy as fuzz


# Трикутна та трапецієподібна функції
def triangular_mf(x, a, b, c):
    if x <= a or x >= c:
        return 0
    elif a < x <= b:
        return (x - a) / (b - a)
    elif b < x < c:
        return (c - x) / (c - b)


a = 2
b = 4
c = 6

x = np.linspace(0, 10, 100)
y = [triangular_mf(i, a, b, c) for i in x]

plt.plot(x, y)
plt.title('Трикутна функція приналежності')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()


def trapezoidal_mf(x, a, b, c, d):
    if x <= a or x >= d:
        return 0
    elif a < x <= b:
        return (x - a) / (b - a)
    elif b < x <= c:
        return 1
    elif c < x < d:
        return (d - x) / (d - c)


a = 2
b = 4
c = 6
d = 8

x = np.linspace(0, 10, 100)
y = [trapezoidal_mf(i, a, b, c, d) for i in x]

plt.plot(x, y)
plt.title('Трапецієподібна функція приналежності')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()

# Проста і двостороння Гаусса
x = np.linspace(-3, 3, 100)

simple_mean = 0
simple_std_dev = 1

symmetric_mean1 = 1
symmetric_std_dev1 = 0.25
symmetric_mean2 = 1
symmetric_std_dev2 = 0.5

simple_gaussian_mf = fuzz.gaussmf(x, simple_mean, simple_std_dev)
symmetric_gaussian_mf = fuzz.gauss2mf(x, symmetric_mean1, symmetric_std_dev1, symmetric_mean2, symmetric_std_dev2)

plt.plot(x, simple_gaussian_mf, label='Simple Gaussian MF')
plt.plot(x, symmetric_gaussian_mf, label='Symmetric Gaussian MF 1')

plt.xlabel('X')
plt.ylabel('Membership Value')
plt.legend()
plt.grid(True)
plt.show()


# Дзвін

def generalized_bell_mf(x, a, b, c):
    return 1 / (1 + abs((x - c) / a) ** (2 * b))


a = 1
b = 2
c = 0

x = np.linspace(-5, 5, 100)
y = [generalized_bell_mf(i, a, b, c) for i in x]

plt.plot(x, y)
plt.title('Функція приналежності "Узагальнений дзвін"')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()


# Сигмоїдальні

def basic_sigmoid_mf(x, a, c):
    return 1 / (1 + np.exp(-a * (x - c)))


a = 1.0
c = 0.0

x = np.linspace(-5, 5, 100)
y = [basic_sigmoid_mf(i, a, c) for i in x]

plt.plot(x, y)
plt.title('Основна одностороння сігмоїдна функція')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()


def additional_sigmoid_mf(x, a, b, c, d):
    return basic_sigmoid_mf(x, a, b) - basic_sigmoid_mf(x, c, d)


a = 1
b = 2
c = 6
d = 7

x = np.linspace(-5, 10, 100)
y = [additional_sigmoid_mf(i, a, b, c, d) for i in x]

plt.plot(x, y)
plt.title('Додаткова двостороння сігмоїдна функція')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()


def asymmetric_sigmoid_mf(x, a, b, c, d):
    return basic_sigmoid_mf(x, a, b) * basic_sigmoid_mf(x, c, d)


a = 1.0
b = 0.5
c = 0.5
b = 0.5

x = np.linspace(-5, 10, 100)
y = [asymmetric_sigmoid_mf(i, a, b, c, d) for i in x]

plt.plot(x, y)
plt.title('Додаткова несиметрична сігмоїдна функція')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()

# Поліноміальні

a = 2
b = 4

x = np.linspace(0, 6, 100)
y = fuzz.zmf(x, a, b)

plt.plot(x, y)
plt.title('Z-функція')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()

a = 1
b = 3
c = 4
d = 6

x = np.linspace(0, 8, 100)
y = fuzz.pimf(x, a, b, c, d)

plt.plot(x, y)
plt.title('PI-функція')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()

a = 2
b = 4

x = np.linspace(0, 6, 100)
y = fuzz.smf(x, a, b)

plt.plot(x, y)
plt.title('S-функція')
plt.xlabel('Значення x')
plt.ylabel('Ступінь приналежності')
plt.grid(True)
plt.show()

# minmax

x_and = np.linspace(0, 1, 100)
y_and = np.minimum(x_and, 0.6)

x_or = np.linspace(0, 1, 100)
y_or = np.maximum(x_or, 0.4)

x_not = np.linspace(0, 1, 100)
y_not = 1 - x_not

plt.figure(figsize=(12, 4))

plt.subplot(131)
plt.plot(x_and, y_and, label='Логічне І (AND)')
plt.xlabel('Вхідне значення')
plt.ylabel('Результат')
plt.title('Логічне І (AND)')
plt.grid(True)
plt.legend()

plt.subplot(132)
plt.plot(x_or, y_or, label='Логічне АБО (OR)')
plt.xlabel('Вхідне значення')
plt.ylabel('Результат')
plt.title('Логічне АБО (OR)')
plt.grid(True)
plt.legend()

plt.subplot(133)
plt.plot(x_not, y_not, label='Логічне НЕ (NOT)')
plt.xlabel('Вхідне значення')
plt.ylabel('Результат')
plt.title('Логічне НЕ (NOT)')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()


# Кон'юнкція / Диз'юнкція

def gaussian_probability(x, mean, std_dev):
    return np.exp(-((x - mean) / (std_dev)) ** 2 / 2) / (std_dev * np.sqrt(2 * np.pi))


mean_A = 0.5
std_dev_A = 0.2
mean_B = 0.7
std_dev_B = 0.15

x = np.linspace(0, 1, 100)
p_A = gaussian_probability(x, mean_A, std_dev_A)
p_B = gaussian_probability(x, mean_B, std_dev_B)

p_AND = np.minimum(p_A, p_B)

p_OR = np.maximum(p_A, p_B)

plt.figure(figsize=(12, 4))

plt.subplot(131)
plt.plot(x, p_A, label='P(A)')
plt.plot(x, p_B, label='P(B)')
plt.xlabel('Вірогідність')
plt.ylabel('Ймовірність події')
plt.title('Ймовірність входження А та В')
plt.grid(True)
plt.legend()

plt.subplot(132)
plt.plot(x, p_AND, label='P(A) AND P(B)')
plt.xlabel('Вірогідність')
plt.ylabel('Ймовірність')
plt.title('Кон\'юнктивний оператор')
plt.grid(True)
plt.legend()

plt.subplot(133)
plt.plot(x, p_OR, label='P(A) OR P(B)')
plt.xlabel('Вірогідність')
plt.ylabel('Ймовірність')
plt.title('Диз\'юнктивний оператор')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()

# NOT

x = np.linspace(0, 10, 100)
membership_function = gaussian_probability(x, 5, 0.2)

complement_function = 1 - membership_function

plt.figure(figsize=(10, 4))

plt.subplot(121)
plt.plot(x, membership_function, label='Нечітка множина')
plt.xlabel('Елементи універсального набору')
plt.ylabel('Ступінь належності')
plt.title('Нечітка множина')
plt.grid(True)
plt.legend()

plt.subplot(122)
plt.plot(x, complement_function, label='Доповнення')
plt.xlabel('Елементи універсального набору')
plt.ylabel('Ступінь належності')
plt.title('Доповнення нечіткої множини')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()
