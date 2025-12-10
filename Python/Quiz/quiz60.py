numbers = [1,2,3,4,5,6,7,8,9,10]

numbers_a = filter(lambda x: x % 2 == 0, numbers)
result_a = map(lambda x: x * x, numbers_a)

print(list(result_a))

words = ["python", "map", "fliter", "lambda", "hi", "educatioin", "code"]

words_a = filter(lambda x: len(x) >= 5, words)
result_b = map(lambda x: len(x), words_a)

print(list(result_b))

scores = [35, 78, 92, 55, 61, 47, 88, 73]

scores_a = filter(lambda x: x >= 60, scores)
result_c = map(lambda x: x + 5, scores_a)

print(list(result_c))
