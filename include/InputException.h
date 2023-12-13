#pragma once

#include "Exception.h"

class InputException : public Exception {

	char inputMessage[80];

public:

	InputException(int, const char[80], const char[80]);
	~InputException();

	void whatInput();
};

float input_price(std::istream&);
std::string input_string(std::istream&);
std::string input_dimension(std::istream&, std::string);
int input_int(std::istream&);
