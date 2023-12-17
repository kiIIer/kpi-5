# Лабораторна робота №8

## Тема

Криптосистема еліптичних кривих

## Виконання

![Рисунок 1 - Число p](image.png)

Повинно бути простим

![Рисунок 2 - Крива](image-1.png)

```python
def check(a, b):
    return ((4 * a * a * a) + (27 * b * b)) % p != 0

>>> print(check(9, 4))

True
```

![Рисунок 3 - Визначити точки](image-2.png)

```python
def elip(x, y):
    return powm(y, 2) == (powm(x, 3) + 9 * x + 4) % p


print(f'{elip(15, 5)}')
print(f'{elip(12, 2)}')
print(f'{elip(0, 15)}')

>>>
False
True
True
```

![Рисунок 4 - Еліптична крива](image-3.png)

![Рисунок 5 - Обираємо точку порядка n](image-4.png)

Оскільки порядок n=19, перша точка не підходить

![Рисунок 6 - Інтервал](image-5.png)

Від 1 до порядок -1

![Рисунок 7 - Нехай д](image-6.png)

![Рисунок 8 - Знаходження Q](image-7.png)

![Рисунок 9 - Онлайн калькулятор точки](image-8.png)

![Рисунок 10 - К](image-9.png)

![Рисунок 11 - Хеш повідомлення](image-10.png)

![Рисунок 12 - Розрахунок r](image-11.png)

![Рисунок 13 - Онлайн калькулятор для r](image-12.png)

```python
(x1, y1) = (4, 11)
print(x1 % n)
>>>
4
```

![Рисунок 14 - пояснення r](image-13.png)

![Рисунок 15 - обрахунок s](image-14.png)

```python
def inverse(x):
    res = 1
    for i in range(n):
        if (x * i) % n == 1:
            return i

print(inverse(9))
>>>
17
```

$d * r = 3 * 4 = 12$

![Рисунок 14 - Значення s](image-15.png)

![Рисунок 15 - пояснення s](image-16.png)

![Рисунок 16 - результат підпису](image-17.png)

![Рисунок 17 - Початок верифікації](image-18.png)

![Рисунок 18 - Дійсний цифровій підпис](image-19.png)
Значення r та s можуть бути тільки в [1, n-1]

![Рисунок 19 - Обчислення w](image-20.png)
Обернений елемент до 1 - це 1

```python
def inverse(x):
    res = 1
    for i in range(n):
        if (x * i) % n == 1:
            return i

print(inverse(1))
>>>
1
```

![Рисунок 22 - Хеш декодування](image-21.png)

![Рисунок 23 - Обрахунок точки](image-22.png)

$u_2 = r * w\ mod\ n = 7 * 1\ mod\ 13 = 7$

```python
def point_addition(P, Q, a, p):
    if P == (0, 0):
        return Q
    if Q == (0, 0):
        return P
    if P == Q:
        num = (3 * P[0] ** 2 + a) % p
        denom = (2 * P[1]) % p
    else:
        num = (Q[1] - P[1]) % p
        denom = (Q[0] - P[0]) % p

    inv_denom = pow(denom, p - 2, p)

    m = (num * inv_denom) % p

    x_r = (m ** 2 - P[0] - Q[0]) % p
    y_r = (m * (P[0] - x_r) - P[1]) % p
    return (x_r, y_r)


def scalar_multiplication(P, n, a, p):
    Q = (0, 0)
    for _ in range(n):
        Q = point_addition(Q, P, a, p)
    return Q


a = 10
b = 12
p = 19
n = 3
P = (5, 15)

R1 = scalar_multiplication(P, u1, a, p)
R2 = scalar_multiplication(Q, u2, a, p)

Result = point_addition(R1, R2, a, p)
print(Result)
>>>
(7, 11)
```

![Рисунок 24 - Обрахуємо v](image-23.png)

$v = x_0\ mod\ n = 7\ mod\ 13 = 7$

![Рисунок 25 - Порівнюємо](image-24.png)

Оскільки значення співпадають, цифровий підпис - правильний

### Звіт

![Рисунок 26 - Звіт](image-25.png)

## Висновок

На цій лабораторній роботі я дослідив криптографію еліптичних кривих, також реалізував базові операціями над точкими в кривих
