numbers = [1,2,3,4,5]

def is_even(x):
    return x % 2 == 0

def is_odd(x):
    return x % 2 !=0


#filter(함수, 리스트) #함수부분을 람다식으로 표현 가능
result = filter(is_even, numbers)
print(list(result))
result = filter(lambda x: x % 2 != 0, numbers)
print(list(result))
