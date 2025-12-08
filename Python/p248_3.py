limit = 10000
i = 1
sumvalue = 0
while sumvalue < 10000:
    sumvalue += i
    i += 1
print("{}를 더할 때 {}을 넘으며 그때의 값은 {}입니다.".format(i-1, limit, sumvalue))
