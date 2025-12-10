file = open("basic.txt", 'w')
print(type(file))

file.write("오늘 점심 뭐 먹지?")

file.close()

with open("basic2.txt", 'w') as file2:
    file2.write("오늘 저녁은 치킨이닭!")

with open("basic2.txt", 'r') as file3:
    text = file3.read()
print(text)
