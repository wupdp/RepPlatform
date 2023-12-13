#include "Exception.h"


Exception::Exception(int inputCode, const char inputMessage[80]) {
    std::strncpy(message, inputMessage, sizeof(message) - 1);
    message[sizeof(message) - 1] = '\0';
    code = inputCode;
}

Exception::~Exception() = default;

void Exception::what() {

	std::cout << "error code " << code << ':' << message << ", ";
}