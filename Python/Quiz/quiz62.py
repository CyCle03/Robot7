class Student:
    def __init__(self, id, name, pnumber):
        self.__id = id
        self.__name = name
        self.__pnumber = pnumber

    def study(self):
        print('공부를 합니다.')
    
    def getId(self):
        return self.__id
    def setId(self, id):
        self.__id = id

    def getName(self):
        return self.__name
    def setName(self, name):
        self.__name = name

    def getPnumber(self):
        return self.__pnumber
    def setPnumber(self, pnumber):
        self.__pnumber = pnumber

    def printInfo(self):
        print(f'{self.__id}, {self.__name}, {self.__pnumber}')

    def __str__(self):
        return '{} / {} / {}\n'.format(self.__id, self.__name, self.__pnumber)

student1 = Student(1, '홍길동', '010-1111-1111')
print(f'{student1.getId()}, {student1.getName()}, {student1.getPnumber()}')

student1.setName('이순신')
student1.setId(2)
student1.setPnumber('010-1234-5678')
student1.printInfo()

student1.study()

print(str(student1))
