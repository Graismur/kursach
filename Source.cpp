#include "factory.h"
#include "funcPort.h"


void portAction(port *p);


int main() {
	int i;
	AbstractFactory *facOne = concreteFactoryCivilianShips::getInstance();
	AbstractFactory *facTwo = concreteFactoryWarships::getInstance();
	port *cnSps = facOne->createPort();
	port *warSps = facTwo->createPort();

	setlocale(LC_ALL, "Russian");

	std::string choosePort[2] = {
		"Гражданские",
		"Боевые"
	};
	while (1) {
		usrmenu(2, choosePort, portAction,
			cnSps,
			warSps
		);
		if (!get_dec("Продолжить работу?(0 - нет) ")) {
			if (get_dec("Сохранить порт в выходном файле?(0 - нет) ")) {
				port tmpPort;
				for (i = 0; i < cnSps->length(); ++i)
					tmpPort += &((*cnSps)[i]);
				for (i = 0; i < warSps->length(); ++i)
					tmpPort += &((*warSps)[i]);
				writeShips(&tmpPort);
			}
			break;
		}
	}
	delete facOne;
	delete facTwo;
	delete cnSps;
	delete warSps;
	return 0;
}

void portAction(port *p) {
	std::string menu[4] = {
		"Добавить",
		"Удалить",
		"Вывести корабли на экран",
		"Считать корабли из файла"
	};
	while (1) {
		try {
			usrmenu(4, menu, p,
				addShip,
				deleteShip,
				printShips,
				readShips
			);
		}
		catch (const std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		if (!get_dec("Продолжить изменение порта?(0 - нет) ")) break;
	}
}