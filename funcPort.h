#pragma once

#include "menu.h"

const std::string PATH("C:/polina/");

void addShip(port *p);			//Добавление кораблей из консоли
void printShips(port *p);		//Вывод порта в консоль
void deleteShip(port *p);		//Удаление кораблей
void readShips(port *p);		//Чтение кораблей из файла
void writeShips(port *p);		//Запись кораблей в файл