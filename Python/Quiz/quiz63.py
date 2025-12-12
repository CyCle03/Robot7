from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def run(self):
        """주행을 표현하는 추상 메소드"""
        pass

class Taxi(Vehicle):
    def run(self):
        print('택시 주행')
    
    def __str__(self):
        return '자식 클래스 Taxi'

class Truck(Vehicle):
    def run(self):
        print('트럭 주행')

    def __str__(self):
        return '자식 클래스 Truck'

class Bus(Vehicle):
    def run(self):
        print('버스 주행')

    def __str__(self):
        return '자식 클래스 Bus'

vehicles: list[Vehicle] = [Taxi(), Truck(), Bus()]

for vehicle in vehicles:
    vehicle.run()
    print(str(vehicle))
