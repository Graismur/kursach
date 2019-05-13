#include "port.h"



port::port() {
	init();
}
port::~port() {
	delete[] sps;
}

void port::operator+=(const Ship &sp) {
	if (size >= reserve) {
		sps = realloc(sps, reserve, reserve + PHASE);
		reserve += PHASE;
	}
	sps[size++] = sp;
}
void port::operator+=(Ship *sp) {
	if (size >= reserve) {
		sps = realloc(sps, reserve, reserve + PHASE);
		reserve += PHASE;
	}
	move(sps[size++], *sp);
}
Ship& port::operator[](int i) {
	return sps[i];
}

int port::length() const {
	return size;
}
void port::remove(int n) {
	if (n >= size)
		throw std::exception("Ошибка, корабля с таким номером не содержится в порту");
	--size;
	for (int i = n; i < size; ++i)
		move(sps[i], sps[i + 1]);
}
void port::getInfo() const {
	for (int i = 0; i < size; ++i) {
		std::cout << i + 1 << ") Тип: " + sps[i].get_type() + " Класс: " + sps[i].get_class_ship() << std::endl;
	}
	std::cout << std::endl;
}

std::istream& operator>>(std::istream &is, port &Obj) {
	Ship sp;
	int dec = get_dec("Введите кол-во добавляемых кораблей: ");
	std::cout << std::endl;
	if (!check_dec(dec, 0))
		throw std::exception("Нельзя добавить меньше одного корабля.");
	for (int i = 0; i < dec; ++i) {
		std::cout << '|' << i + 1 << '|';
		std::cout << std::endl;
		try {
			is >> sp;
		}
		catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
			std::cout
				<< "Из " << dec
				<< " кораблей в базу были добавлены "
				<< i << std::endl << std::endl;
			return is;
		}
		Obj += &sp;
		std::cout << "Корабль успешно добавлена в порт. ";
		std::cout << std::endl << std::endl;
	}
	return is;
}
std::ostream& operator<<(std::ostream &os, const port &Obj) {
	for (int i = 0; i < Obj.size; ++i) {
		os << '|' << i + 1 << '|';
		os << std::endl;
		os << Obj.sps[i];
		os << std::endl;
	}
	return os;
}

std::ifstream& operator>>(std::ifstream& ifs, port &Obj) {
	Ship sp;
	int dec = get_dec("Введите кол-во добавляемых коралей: ");
	std::cout << std::endl;
	if (!check_dec(dec, 0))
		throw std::exception("Нельзя добавить меньше одного корабля.");
	for (int i = 0; i < dec; ++i) {
		std::cout << '|' << i + 1 << '|' << ' ';
		try {
			ifs >> sp;
		}
		catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
			std::cout
				<< "Из " << dec
				<< " кораблей в базу были добавлены "
				<< i << std::endl << std::endl;
			return ifs;
		}
		Obj += &sp;
		std::cout << "Корабль успешно добавлен в порт. ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return ifs;
}
std::ofstream& operator<<(std::ofstream& ofs, const port &Obj) {
	int i, j, k;
	int size = 1;
	std::string *type = new std::string[Obj.size];
	type[0] = Obj.sps[0].get_type();
	for (i = 1; i < Obj.size; ++i) {
		for (j = 0; j < size; ++j) {
			if (type[j] != Obj.sps[i].get_type()) {
				type[size++] = Obj.sps[i].get_type();
			}
		}
	}
	for (i = 0; i < size; ++i) {
		ofs << "Тип: " << type[i];
		ofs << std::endl;
		ofs << std::endl;
		k = 1;
		for (j = 0; j < Obj.size; ++j) {
			if (type[i] == Obj.sps[j].get_type()) {
				ofs << '|' << k++ << '|';
				ofs << std::endl;
				ofs << Obj.sps[j];
				ofs << std::endl;
			}
		}
		ofs << std::endl;
		ofs << std::endl;
	}
	std::cout << std::endl;
	delete[] type;
	return ofs;
}

void port::init() {
	reserve = PHASE;
	size = 0;
	sps = new Ship[reserve];
}