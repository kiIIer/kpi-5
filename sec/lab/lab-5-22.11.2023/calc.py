def power_modder(x, a, mod):
    result = 1
    for i in range(a):
        result *= x
        result %= mod
    print(f'{x} ^ {a} mod {mod} = {result}')
    return result

power_modder(4, 34, 53)