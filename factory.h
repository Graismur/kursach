#pragma once

#include "AbstractFactory.h"


class concreteFactoryCivilianShips : public AbstractFactory {
public:
	civilianShips* createPort() override { return new civilianShips(); }					//������� �������� ������� ���� ��������
	static concreteFactoryCivilianShips *getInstance() {									//������� ��������� ��������� �� �������
		if (!instance)
			instance = new concreteFactoryCivilianShips();
		return instance;
	}
private:
	concreteFactoryCivilianShips() {};
	static concreteFactoryCivilianShips *instance;								//��������� �� �������
};
concreteFactoryCivilianShips* concreteFactoryCivilianShips::instance = nullptr;

class concreteFactoryWarships : public AbstractFactory {
public:
	warships* createPort() override { return new warships(); }	//������� �������� ������� ���� ��������
	static concreteFactoryWarships *getInstance() {							//������� ��������� ��������� �� �������
		if (!instance)
			instance = new concreteFactoryWarships();
		return instance;
	}
private:
	concreteFactoryWarships() {};
	static concreteFactoryWarships *instance;								//��������� �� �������
};
concreteFactoryWarships* concreteFactoryWarships::instance = nullptr;