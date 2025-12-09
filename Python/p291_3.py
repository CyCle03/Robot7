# def function1(*values, valueA, valueB):
#     pass
# function1(1, 2, 3, 4, 5)

def function2(*values, valueA=10, valueB=20):
    pass
function2(1, 2, 3, 4, 5)

def function3(valueA, valueB, *values):
    pass
function3(1, 2, 3, 4, 5)

def function4(valueA=10, valueB=20, *values):
    pass
function4(1, 2, 3, 4, 5)
