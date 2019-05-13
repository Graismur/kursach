#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include "fun.h"

class ShipBuilder;

class Ship {
public:

	Ship& operator=(const Ship &sp);	//Перегрузка оператора =

	friend std::istream& operator>>(std::istream &is, Ship &sp);		//Ввод корабля из консоли
	friend std::ostream& operator<<(std::ostream &os, const Ship &sp);	//Вывод корабля в консоль

	friend std::ifstream& operator>>(std::ifstream &ifs, Ship &sp);			//Ввод корабля из файла
	friend std::ofstream& operator<<(std::ofstream &ofs, const Ship &sp);	//Вывод корабля в файл

	friend void move(Ship &sp1, Ship &sp2);									//Функция перемещения кораблей

	const std::string& get_type() const;			//Получение типа
	const std::string& get_class_ship() const;	//			класса
	const std::string& get_special() const;		//			является ли специальным
	const std::string& get_dim() const;			//			габаритов
	const std::string& get_area() const;		//			района плавания
	const std::string& get_type_pp() const;		//			типа энергитической установки
	const std::string& get_dis() const;			//			водоизмещение
	const std::string& get_weight() const;		//			перевозимый вес
	const std::string& get_crew() const;		//			число экипажа
	const std::string& get_pas() const;			//			число пассажиров
	const std::string& get_speed() const;		//			скорость

	void set_type(const std::string& type);				//Уставка типа
	void set_class_ship(const std::string& class_ship);	//		класса
	void set_special(const std::string& special);		//		является ли специальным 
	void set_dim(const std::string& dim);				//		габаритов
	void set_area(const std::string& area);				//		района плавания
	void set_type_pp(const std::string& type_pp);		//		типа энергитической установки
	void set_dis(const std::string& dis);				//		водоизмещения
	void set_weight(const std::string& weight);			//		веса
	void set_crew(const std::string& crew);				//		экипажа
	void set_pas(const std::string& pas);				//		пассажиров
	void set_speed(const std::string& speed);			//		скорости


private:
	std::string type;							//тип
	std::string class_ship;						//класс
	std::string special;						//является ли специальным
	std::string dim;							//габариты
	std::string area;							//район плавания
	std::string type_pp;						//тип энергитической установки
	std::string dis;							//водоизмещение
	std::string weight;							//перевозимый вес
	std::string crew;							//число экипажа
	std::string pas;							//число пассажиров
	std::string speed;							//скорость
};