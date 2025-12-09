listtwo = [2 ** n for n in range(1, 11, 1)]
print(listtwo)

listthree = [i * 3 for i in range(1, 10, 1)]
print(listthree)

words = ['apple', 'kiwi', 'banana', 'grape', 'pear']

long_word = [ word for word in words if len(word) >= 5 ]
print(long_word)
