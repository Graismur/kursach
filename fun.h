#pragma once

#include <string>
#include <iostream>

int get_dec(const std::string &str);								//Функция получения числа с выводом приглашения
bool check_dec(int dec, int left, int right = 2147483647);			//Проверка числа на принадлежность задоному интервалу
bool check_un_dec(const std::string &str);							//Проверка строки на содержание беззнаково числа
bool check_un_dec_int(const std::string &str);						
bool match(const char *str, const char *pat);