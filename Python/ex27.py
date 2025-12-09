# 4개 사칙연산 함수
def plus(a, b):
    return a + b
def minus(a, b):
    return a - b
def multiple(a, b):
    return a * b
def divide(a, b):
    if b == 0:
        print("0으로 나눌 수 없습니다.")
        return
    return a / b

print("두 정수를 입력하세요.")
a = int(input("a : "))
b = int(input("b : "))

print(f"{a} + {b} = {plus(a, b)}\n"
      f"{a} - {b} = {minus(a, b)}\n"
      f"{a} * {b} = {multiple(a, b)}\n"
      f"{a} / {b} = {divide(a, b)}\n")
