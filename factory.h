#pragma once

#include "AbstractFactory.h"


class concreteFactoryCivilianShips : public AbstractFactory {
public:
	civilianShips* createPort() override { return new civilianShips(); }					//Функция создания первого типа кораблей
	static concreteFactoryCivilianShips *getInstance() {									//Функция получения указателя на фабрику
		if (!instance)
			instance = new concreteFactoryCivilianShips();
		return instance;
	}
private:
	concreteFactoryCivilianShips() {};
	static concreteFactoryCivilianShips *instance;								//Указатель на фабрику
};
concreteFactoryCivilianShips* concreteFactoryCivilianShips::instance = nullptr;

class concreteFactoryWarships : public AbstractFactory {
public:
	warships* createPort() override { return new warships(); }	//Функция создания второго типа кораблей
	static concreteFactoryWarships *getInstance() {							//Функция получения указателя на фабрику
		if (!instance)
			instance = new concreteFactoryWarships();
		return instance;
	}
private:
	concreteFactoryWarships() {};
	static concreteFactoryWarships *instance;								//Указатель на фабрику
};
concreteFactoryWarships* concreteFactoryWarships::instance = nullptr;