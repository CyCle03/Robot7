import random

def func1():
    while True:
        yield random.randint(1, 100)
    
generator = func1()

for _ in range(5):
    print(next(generator))
