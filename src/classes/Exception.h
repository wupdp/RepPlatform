#include <iostream>
#include <cstring>

#pragma once
class Exception {

	char message[80];
	int code;

public:

	Exception(int, const char[80]);
	~Exception();

	void what();
};
