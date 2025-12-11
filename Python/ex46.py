class Person:
    def __init__(self, name):
        self.__name = name
    def get_name(self):
        return self.__name

#main

soonsin = Person('이순신')

print(soonsin.get_name())
