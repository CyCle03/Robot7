example_list = ['요소A', '요소B', '요소C']

print("# 단순 출력")
print(example_list)
print()

print("# enumberate() 함수 적용 출력")
print(enumerate(example_list))
print()

print("# list() 함수로 강제 변환 출력")
print(list(enumerate(example_list)))
print()

alist = list(enumerate(example_list))
print(alist[0])
print(type(alist[0]))
print("# 튜플 리스트 출력하기")
for index, value in enumerate(example_list):
    print("{}번 째 요소는 {} 입니다.".format(index, value))
