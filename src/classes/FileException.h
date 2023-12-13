#pragma once

#include <fstream>
#include "Exception.h"

class FileException : public Exception {

	char fileMessage[80];

public:

	FileException(int, const char[80], const char[80]);
	~FileException();

	void whatFile();
};

int exist_file(const char* name_file);