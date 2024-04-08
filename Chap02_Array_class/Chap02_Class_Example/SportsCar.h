#pragma once
#include "Car.h"

class SportsCar : public Car //카로부터 상속받는다
{
public:
	bool bTurbo;
	void setTurbo(bool bTur) {
		bTurbo = bTur;
	}
	void speedUp() {
		if (bTurbo)
			speed += 20;
		else
			Car::speedUp(); //car클래스에 있는 함수 쓰고 싶을때 :: 쓴다
	}


};