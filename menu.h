#pragma once

#include "port.h"
#include <cstdarg>

typedef port* paramOne;						//Объявление синонима paramOne к ShipPort*
typedef void(*my_ptr_fun_param)(paramOne);		//объявление синонима к функции принимающей paramOne и возвращающей void

int usr_choose(int amount, const std::string *str);	//Функция вывода меню и считывания выбранного пользователем пункта

void usrmenu(int amount, const std::string *str, paramOne libBks, my_ptr_fun_param func, ...);	//Пользовательское меню с передачей функция для каждого пункта
void usrmenu(int amount, const std::string *str, my_ptr_fun_param func, paramOne libBks, ...);	//Пользовательское меню с передачей парметра функции для каждого пункта