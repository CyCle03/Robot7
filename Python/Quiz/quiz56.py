op = input('연산자 : ')
a = int(input('a : '))
b = int(input('b : '))

if op == '+':
    print(a, '+', b, '=', a + b)
elif op == '-':
    print(a, '-', b, '=', a - b)
elif op == '*':
    print(a, '*', b, '=', a * b)
elif op == '/':
    print(a, '/', b, '=', a / b)
else:
    print("연산자 오류")

print('3 혹은 5의 배수 판별기')
c = int(input('정수를 입력하세요: '))
if c % 3 == 0:
    print('OK')
elif c % 5 == 0:
    print('OK')
else:
    print('NO')
