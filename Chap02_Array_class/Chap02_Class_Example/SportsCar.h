#pragma once
#include "Car.h"

class SportsCar : public Car //ī�κ��� ��ӹ޴´�
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
			Car::speedUp(); //carŬ������ �ִ� �Լ� ���� ������ :: ����
	}


};