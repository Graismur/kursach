#include "funcPort.h"

void addShip(port *p) {
	try {
		std::cin >> *p;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
void printShips(port *p) {
	std::cout << std::endl;

	if (!(p->length())) {
		std::cout << "Порт пуст." << std::endl << std::endl;
		return;
	}
	std::cout << *p;
}
void deleteShip(port *p) {
	int dec;

	std::cout << std::endl;

	if (!(p->length())) {
		std::cout << "Порт пуст." << std::endl << std::endl;
		return;
	}

	p->getInfo();

	dec = get_dec("Введите номер удаляемого корабля: ");

	try {
		p->remove(--dec);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
		return;
	}
	std::cout << "Успешно удалено!" << std::endl << std::endl;
}
void readShips(port *p) {
	std::string PathRead;
	std::ifstream in;

	std::cout << std::endl;
	std::cout << "Введите имя файла" << std::endl;
	std::cout << PATH;
	std::cin >> PathRead;
	PathRead = PATH + PathRead;

	in.open(PathRead);

	if (!in.is_open()) {
		throw std::exception("Файл не был открыт");
	}
	try {
		in >> *p;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}
void writeShips(port *p) {
	std::string PathWrite;
	std::ofstream out;

	std::cout << std::endl;
	std::cout << "Введите имя файла" << std::endl;
	std::cout << PATH;
	std::cin >> PathWrite;
	PathWrite = PATH + PathWrite;

	out.open(PathWrite);

	if (!out.is_open()) {
		throw std::exception("Файл не был открыт");
	}

	out << *p;
}