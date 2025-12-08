import time #파이썬 내부 모듈

number = 0

target_tick = time.time() + 3

while time.time() < target_tick:
    number += 1
    print('3초 동안 {}번 반복했습니다.'.format(number))
