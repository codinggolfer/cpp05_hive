#include "intern.hpp"

intern::intern() {}

intern::intern (const intern& copy) {
	(this != &copy)
		return ;
}

intern& intern::operator=(const intern& other) {
	if (this != &other)
		return *this;
	return *this;
}
