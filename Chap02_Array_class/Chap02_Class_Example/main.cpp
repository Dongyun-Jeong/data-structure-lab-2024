#include <cstdio>
//#include "Car.h"
//#include "SportsCar.h"
#include "Rectangle.h"

int main() {
	/*
	//car 클래스 사용
	Car myCar(50, "K3", 4);
	Car yourCar(100, "K5", 3);
	myCar.display();
	yourCar.display();
	myCar.whereAmI();
	yourCar.whereAmI();

	//sportscar 클래스 사용
	SportsCar scar;
	scar.speedUp();
	*/
	Rectangle r(10, 20);
	double perimeter= r.getPerimeter();
	std::cout << "Rectangle 1: " << std::endl; // c++에서 쓰는거(#include iostream 써서 가능) / endl 줄바꿈.
	std::cout << "Area: " << r.getArea() << std::endl;
	std::cout << "Perimeter: " << perimeter << std::endl;
	std::cout << "is square? " << std::boolalpha << r.isSquare() << std::endl;
}