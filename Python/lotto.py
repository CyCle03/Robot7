import random

seven = random.sample(range(1,46), 7)
lotto = seven[:6]
print('로또 번호 : ', *sorted(lotto))
print('보너스 번호 : ', seven[6])
