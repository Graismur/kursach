#pragma once

#include "varShip.h"

class AbstractFactory {
public:
	virtual port* createPort() = 0;
};