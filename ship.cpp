#include "ship.h"

Ship& Ship::operator=(const Ship &sp) {
	if (this != &sp) {
		this->type = sp.type;
		this->class_ship = sp.class_ship;
		this->special = sp.special;
		this->dim = sp.dim;
		this->area = sp.area;
		this->type_pp = sp.type_pp;
		this->dis = sp.dis;
		this->weight = sp.weight;
		this->crew = sp.crew;
		this->pas = sp.pas;
		this->speed = sp.speed;
	}
	return *this;
}

std::istream& operator>>(std::istream &is, Ship &sp) {

	bool flag = false;

	std::string dimA, dimB, dimC;

	std::cout << "Введите тип корабля: ";
	std::getline(is, sp.type, '\n');
	if (sp.type.length()) flag = true;

	std::cout << "Введите класс корабля: ";
	std::getline(is, sp.class_ship, '\n');
	if (sp.class_ship.length()) flag = true;

	std::cout << "Является ли спец. кораблем? ";
	std::getline(is, sp.special, '\n');
	if (sp.special.length()) flag = true;

	std::cout << "Введите габариты(A x B x C) в метрах: " << std::endl;
	std::cout << "\tВведите длину: ";
	std::getline(is, dimA, '\n');
	if (!check_un_dec(dimA))
		throw std::exception("Неверно введен параметр.");
	std::cout << "\tВведите ширину: ";
	std::getline(is, dimB, '\n');
	if (!check_un_dec(dimB))
		throw std::exception("Неверно введен параметр.");
	std::cout << "\tВведите высоту: ";
	std::getline(is, dimC, '\n');
	if (!check_un_dec(dimC))
		throw std::exception("Неверно введен параметр.");

	if (!dimA.length()) dimA = "o";
	if (!dimB.length()) dimB = "o";
	if (!dimC.length()) dimC = "o";
	sp.dim = dimA + " x " + dimB + " x " + dimC;

	if (sp.dim.length()) flag = true;

	std::cout << "Введите район плавания: ";
	std::getline(is, sp.area, '\n');
	if (sp.area.length()) flag = true;

	std::cout << "Введите тип энергитической установки: ";
	std::getline(is, sp.type_pp, '\n');
	if (sp.type_pp.length()) flag = true;

	std::cout << "Введите водоизмещение в кубометрах: ";
	std::getline(is, sp.dis, '\n');
	if (!check_un_dec(sp.dis))
		throw std::exception("Неверно введен параметр.");
	if (sp.dis.length()) flag = true;

	std::cout << "Введите перевозимый вес в тоннах: ";
	std::getline(is, sp.weight, '\n');
	if (!check_un_dec(sp.weight))
		throw std::exception("Неверно введен параметр.");
	if (sp.weight.length()) flag = true;

	std::cout << "Введите число экипажа: ";
	std::getline(is, sp.crew, '\n');
	if (!check_un_dec_int(sp.crew))
		throw std::exception("Неверно введен параметр.");
	if (sp.crew.length()) flag = true;

	std::cout << "Введите число пассажиров: ";
	std::getline(is, sp.pas, '\n');
	if (!check_un_dec_int(sp.pas))
		throw std::exception("Неверно введен параметр.");
	if (sp.pas.length()) flag = true;

	std::cout << "Введите скорость в км/ч: ";
	std::getline(is, sp.speed, '\n');
	if (!check_un_dec(sp.speed))
		throw std::exception("Неверно введен параметр.");
	if (sp.speed.length()) flag = true;

	std::cout << std::endl;

	if (!flag) {
		throw std::exception("Введен пустой корабль!");
	}
	return is;
}
std::ostream& operator<<(std::ostream &os, const Ship &sp) {
	int width_one = 25;
	int width_two = 18;


	os.width(width_one);
	os << "Тип: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.type;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Класс: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.class_ship;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "Скорость(км/ч): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.speed;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Габариты(метры): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.dim;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "Район плавания: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.area;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Тип ЭУ: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.type_pp;
	os.unsetf(std::ios::left);
	os << std::endl;


	os.width(width_one);
	os << "Водоизмещение(м^3): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.dis;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Перевозимый вес(тонны): ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.weight;
	os.unsetf(std::ios::left);
	os << std::endl;

	os.width(width_one);
	os << "Число экипажа: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.crew;
	os.unsetf(std::ios::left);
	os.width(width_one);
	os << "Число пассажиров: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.pas;
	os.unsetf(std::ios::left);
	os << std::endl;


	os.width(width_one);
	os << "Специальный: ";
	os.width(width_two);
	os.setf(std::ios::left);
	os << sp.special;
	os.unsetf(std::ios::left);
	os << std::endl;

	os << std::endl;

	return os;
}

std::ifstream& operator>>(std::ifstream &ifs, Ship &sp) {
	std::string str;

	std::string dimA, dimB, dimC;

	bool flag = false;

	do {
		str.clear();

		std::getline(ifs, str, '\n');

		if (!str.length())
			throw std::exception("Корабль не найден!");

		else if (match(str.c_str(), "Type: ?*")) {
			sp.type = std::string(str.c_str() + 6);
			flag = true;
		}
		else if (match(str.c_str(), "Class: ?*")) {
			sp.class_ship = std::string(str.c_str() + 7);
			flag = true;
		}
		else if (match(str.c_str(), "Special: ?*")) {
			sp.special = std::string(str.c_str() + 9);
			flag = true;
		}
		else if (match(str.c_str(), "Length: ?*")) {
			dimA = std::string(str.c_str() + 8);
			if (!check_un_dec(dimA))
				throw std::exception("Считано неверная длина.");
			flag = true;
		}
		else if (match(str.c_str(), "Width: ?*")) {
			dimB = std::string(str.c_str() + 7);
			if (!check_un_dec(dimB))
				throw std::exception("Считано неверная ширина.");
			flag = true;
		}
		else if (match(str.c_str(), "Height: ?*")) {
			dimC = std::string(str.c_str() + 8);
			if (!check_un_dec(dimC))
				throw std::exception("Считано неверная высота.");
			flag = true;
		}
		else if (match(str.c_str(), "Area: ?*")) {
			sp.area = std::string(str.c_str() + 6);
			flag = true;
		}
		else if (match(str.c_str(), "Type of power plant: ?*")) {
			sp.type_pp = std::string(str.c_str() + 21);
			flag = true;
		}
		else if (match(str.c_str(), "Displacement: ?*")) {
			sp.dis = std::string(str.c_str() + 14);
			if (!check_un_dec(sp.dis))
				throw std::exception("Считано неверное водоизмещение.");
			flag = true;
		}
		else if (match(str.c_str(), "Transported weight: ?*")) {
			sp.weight = std::string(str.c_str() + 20);
			if (!check_un_dec(sp.weight))
				throw std::exception("Считан неверный перевозимый вес.");
			flag = true;
		}
		else if (match(str.c_str(), "Crew number: ?*")) {
			sp.crew = std::string(str.c_str() + 13);
			if (!check_un_dec_int(sp.crew))
				throw std::exception("Считано неверное число экипажа");
		}
		else if (match(str.c_str(), "Number of passengers: ?*")) {
			sp.pas = std::string(str.c_str() + 22);
			if (!check_un_dec_int(sp.pas))
				throw std::exception("Считано неверное число пассажиров.");
			flag = true;
		}
		else if (match(str.c_str(), "Speed: ?*")) {
			sp.speed = std::string(str.c_str() + 7);
			if (!check_un_dec(sp.speed))
				throw std::exception("Считана неверная скорость.");
			flag = true;
		}
		else if (match(str.c_str(), "-*")) {
			break;
		}
	} while (1);

	if (!flag) {
		throw std::exception("Считан пустой корабль!");
	}

	if (!dimA.length()) dimA = "o";
	if (!dimB.length()) dimB = "o";
	if (!dimC.length()) dimC = "o";
	sp.dim = dimA + " x " + dimB + " x " + dimC;

	return ifs;
}
std::ofstream& operator<<(std::ofstream &ofs, const Ship &sp) {
	int width_one = 25;
	int width_two = 18;


	ofs.width(width_one);
	ofs << "Тип: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.type;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Класс: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.class_ship;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs.width(width_one);
	ofs << "Скорость(км/ч): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.speed;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Габариты(метры): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.dim;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs.width(width_one);
	ofs << "Район плавания: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.area;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Тип ЭУ: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.type_pp;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;


	ofs.width(width_one);
	ofs << "Водоизмещение(м^3): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.dis;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Перевозимый вес(тонны): ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.weight;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs.width(width_one);
	ofs << "Число экипажа: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.crew;
	ofs.unsetf(std::ios::left);
	ofs.width(width_one);
	ofs << "Число пассажиров: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.pas;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;


	ofs.width(width_one);
	ofs << "Специальный: ";
	ofs.width(width_two);
	ofs.setf(std::ios::left);
	ofs << sp.special;
	ofs.unsetf(std::ios::left);
	ofs << std::endl;

	ofs << std::endl;

	return ofs;
}

void move(Ship &sp1, Ship &sp2) {
	if (&sp1 != &sp2) {
		sp1.type = std::move(sp2.type);
		sp1.class_ship = std::move(sp2.class_ship);
		sp1.special = std::move(sp2.special);
		sp1.dim = std::move(sp2.dim);
		sp1.area = std::move(sp2.area);
		sp1.type_pp = std::move(sp2.type_pp);
		sp1.dis = std::move(sp2.dis);
		sp1.weight = std::move(sp2.weight);
		sp1.crew = std::move(sp2.crew);
		sp1.pas = std::move(sp2.pas);
		sp1.speed = std::move(sp2.speed);
	}
}

const std::string& Ship::get_type() const {
	return type;
}
const std::string& Ship::get_class_ship() const {
	return class_ship;
}
const std::string& Ship::get_special() const {
	return special;
}
const std::string& Ship::get_dim() const {
	return dim;
}
const std::string& Ship::get_area() const {
	return area;
}
const std::string& Ship::get_type_pp() const {
	return type_pp;
}
const std::string& Ship::get_dis() const {
	return dis;
}
const std::string& Ship::get_weight() const {
	return weight;
}
const std::string& Ship::get_crew() const {
	return crew;
}
const std::string& Ship::get_pas() const {
	return pas;
}
const std::string& Ship::get_speed() const {
	return speed;
}


void Ship::set_type(const std::string& type) {
	this->type = type;
}
void Ship::set_class_ship(const std::string& class_ship) {
	this->class_ship = class_ship;
}
void Ship::set_special(const std::string& special) {
	this->special = special;
}
void Ship::set_dim(const std::string& dim) {
	this->dim = dim;
}
void Ship::set_area(const std::string& area) {
	this->area = area;
}
void Ship::set_type_pp(const std::string& type_pp) {
	this->type_pp = type_pp;
}
void Ship::set_dis(const std::string& dis) {
	this->dis = dis;
}
void Ship::set_weight(const std::string& weight) {
	this->weight = weight;
}
void Ship::set_crew(const std::string& crew) {
	this->crew = crew;
}
void Ship::set_pas(const std::string& pas) {
	this->pas = pas;
}
void Ship::set_speed(const std::string& speed) {
	this->speed = speed;
}