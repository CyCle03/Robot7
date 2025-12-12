class Student:
    def __init__(self, id, name):
        self.__id = id
        self.__name = name

    @property
    def id(self):
        return self.__id
    @id.setter
    def id(self, value):
        if value < 0:
            raise ValueError('id는 양의 숫자여야 합니다.')
        self.__id = value

    @property
    def name(self):
        return self.__name
    @name.setter
    def name(self, value):
        self.__name = value

chulsoo = Student(1, '철수')

chulsoo.id = 2
chulsoo.name = '처얼~쑤'

print(chulsoo.id, ':', chulsoo.name)
