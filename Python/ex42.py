class Student:
    def __init__(self, name, korean, math, english, science):
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science

students = [
    Student("윤인성", 87, 98, 88, 95),
    Student("연하진", 92, 98, 96, 98)
]

print(students[0].name)
print(students[1].name)
print()

for person in students:
    print('{}{}'.format(person.name, person.korean))
