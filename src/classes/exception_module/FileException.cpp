#include "../../../include/FileException.h"

FileException::FileException(int input_code, const char first_message[80], const char second_message[80])
        : Exception(input_code, first_message) {
    std::strncpy(fileMessage, second_message, sizeof(fileMessage) - 1);
    fileMessage[sizeof(fileMessage) - 1] = '\0';
}

FileException::~FileException() = default;

void FileException::whatFile() const{

    this->what();
    std::cout << fileMessage << '\n';
}

bool exist_file(const char* filename) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw FileException(-1, "File not found", "File does not exist or cannot be opened.");
        }
        return true; // Файл существует
    } catch (const FileException& e) {
        e.whatFile();
        return false; // Файл не существует
    }
}


