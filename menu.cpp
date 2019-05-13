﻿#include "menu.h"

int usr_choose(int amount, const std::string *str) {
	int i = 0;
	std::cout << std::endl;
	std::cout.setf(std::ios::left);
	for (i = 0; i < amount; ++i) {
		std::cout << i + 1 << ". ";
		std::cout << str[i];
		std::cout << std::endl;
	}
	std::cout.unsetf(std::ios::left);
	std::cout << std::endl << std::endl;
	i = get_dec("Выберете пункт меню: ");
	if (!check_dec(i, 0, amount + 1))
		throw std::exception("Пункт меню выбран неверно");
	return i;
}
void usrmenu(int amount, const std::string *str, paramOne libBks, my_ptr_fun_param func, ...) {
	int dec;
	my_ptr_fun_param f = nullptr;
	try {
		dec = usr_choose(amount, str);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << "Return..." << std::endl;
		return;
	}
	va_list ap;
	va_start(ap, func);
	if (dec == 1) {
		func(libBks);
		return;
	}
	for (int i = 2; i <= amount; ++i) {
		f = (my_ptr_fun_param)va_arg(ap, my_ptr_fun_param);
		if (dec == i) {
			f(libBks);
			return;
		}
	}
	va_end(ap);
}
void usrmenu(int amount, const std::string *str, my_ptr_fun_param func, paramOne libBks, ...) {
	int dec;
	paramOne prm;
	try {
		dec = usr_choose(amount, str);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << "Return..." << std::endl;
		return;
	}
	va_list ap;
	va_start(ap, libBks);
	if (dec == 1) {
		func(libBks);
		return;
	}
	for (int i = 2; i <= amount; ++i) {
		prm = (paramOne)va_arg(ap, paramOne);
		if (dec == i) {
			func(prm);
			return;
		}
	}
	va_end(ap);
}