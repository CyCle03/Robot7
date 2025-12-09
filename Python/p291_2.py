def mul(*values):
    total = 1
    for value in values:
        total *= value
    return total

print(mul(5, 7, 9, 10))
