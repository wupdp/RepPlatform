#include "FileException.h"

FileException::FileException(int input_code, const char first_message[80], const char second_message[80])
        : Exception(input_code, first_message) {
    std::strncpy(fileMessage, second_message, sizeof(fileMessage) - 1);
    fileMessage[sizeof(fileMessage) - 1] = '\0';
}

FileException::~FileException() = default;

void FileException::whatFile() {

    this->what();
    std::cout << fileMessage << '\n';
}

int exist_file(const char *name_file) {

    std::ifstream in_test(name_file, std::ios::in);
    try {
        if (!in_test)
            throw (FileException(1, "file error", "file not exist"));
        if (!in_test.is_open())
            throw (FileException(3, "file error", "file didn't open"));
        in_test.seekg(0, std::ios::end);
        if (in_test.tellg() == 0)
            throw (FileException(2, "file error", "file is empty"));
    }
    catch (FileException obj) {
        obj.whatFile();
        system("pause");
        return 0;
    }
    return 1;
}
