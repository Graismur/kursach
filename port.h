#pragma once

#include "ship.h"
#include "realloc.h"

#define PHASE 10

class port {
public:
	port();									//Конструктор по умолчанию

	void operator+=(const Ship &sp);		//Перегрузка += для добавления корабля в порт
	void operator+=(Ship *sp);				//Тоже самое, но не копирует корабль, а забирает переданный
	Ship& operator[](int i);				//Для доступа к конкретному кораблю

	void remove(int n);						//Удаление корабля
	int length() const;						//Получение размер порта
	void getInfo() const;						//Получение краткой информации о порте

	friend std::istream& operator>>(std::istream &is, port &Obj);			//Ввод порта из консоли
	friend std::ostream& operator<<(std::ostream &os, const port &Obj);		//Вывод порта в консоль

	friend std::ifstream& operator>>(std::ifstream &ifs, port &Obj);		//Ввод порта из файла
	friend std::ofstream& operator<<(std::ofstream &ofs, const port &Obj);	//Вывод порта в файл

	~port();			//Деструктор
private:
	Ship *sps;			//Массив из кораблей
	int size;			//Длина массива
	int reserve;		//Зарезервированное место(кратно PHASE)

	void init();		//Начальная инициализация
};