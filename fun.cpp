#include "fun.h"

int get_dec(const std::string &str) {
	int dec;
	std::cout << str;
	std::cin >> dec;
	std::cin.get();
	return dec;
}
bool check_dec(int dec, int left, int right) {
	return (dec > left) ? (dec < right) ? true : false : false;
}
bool check_un_dec(const std::string &str) {
	int count = 0;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == '.') {
			if (++count > 1) return false;
		}
		else if (str[i] < 48 || str[i] > 57) return false;
	}
	return true;
}
bool check_un_dec_int(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] < 48 || str[i] > 57) return false;
	}
	return true;
}
bool match(const char *str, const char *pat) {
	for (;; ++str, ++pat) {
		switch (*pat) {
		case '\0':
			return (*str == '\0');
		case '*':
			for (int i = 0; ; ++i) {
				if (match(str + i, pat + 1)) return true;
				if (!str[i]) return false;
			}
		case '?':
			if (!*str) return false;
			break;
		default:
			if (*str != *pat) return false;
		}
	}
}