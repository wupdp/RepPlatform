#include <ctime>
#include <iomanip>
#include "../../../include/InputException.h"

InputException::InputException(int inputCode, const char firstMessage[80], const char secondMessage[80])
        : Exception(inputCode, firstMessage) {
    std::strncpy(inputMessage, secondMessage, sizeof(inputMessage) - 1);
    inputMessage[sizeof(inputMessage) - 1] = '\0';
}

InputException::~InputException() = default;

void InputException::whatInput() {

    this->what();
    std::cout << inputMessage << '\n';
}

std::string input_string(std::istream& is)
{
    bool flag;
    char BUFF[80];
    std::string str;
    do
    {
        flag = true;
        try
        {
            rewind(stdin);

            is.getline(BUFF, sizeof BUFF);
            str = BUFF;
            if (str.length() == 0)
                throw InputException(5, "string input error", "you haven't entered anything");
            for (int i = 0; i < str.length(); i++)
                if ((str[i] > 'z' || str[i] < 'a') && (str[i] > 'Z' || str[i] < 'A'))
                {
                    throw InputException(3, "string input error", "change to the English layout");
                }
        }
        catch (InputException& obj)
        {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return str;
}

int input_int(std::istream& is)
{
    int num;
    bool flag;
    do
    {
        flag = true;
        try
        {
            rewind(stdin);
            is >> num;
            if (is.fail() || std::cin.peek() != '\n')
            {
                throw InputException(1, "number input error", "you entered a character, enter numbers");
            }
        }
        catch (InputException& obj)
        {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return num;
}

bool containsNonAlphanumeric(const std::string& password) {
    for (char ch : password) {
        if (!std::isalnum(ch)) {
            return true;
        }
    }
    return false;
}

std::string input_password(std::istream& is) {
    std::string password;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите пароль: ";
            std::getline(is, password);

            // Проверка условий для пароля
            if (password.length() < 8) {
                throw InputException(10, "Password input error", "Пароль должен содержать не менее 8 символов");
            }

            if (containsNonAlphanumeric(password)) {
                throw InputException(11, "Password input error", "Пароль должен содержать только латинские символы и цифры");
            }

        } catch (InputException& obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return password;
}

std::string input_username(std::istream& is) {
    std::string username;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите имя пользователя: ";
            std::getline(is, username);

            // Проверка условий для имени пользователя
            if (username.empty()) {
                throw InputException(20, "Username input error", "Имя пользователя не может быть пустым");
            }

            if (containsNonAlphanumeric(username)) {
                throw InputException(21, "Username input error", "Имя пользователя должно содержать только латинские символы и цифры");
            }

        } catch (InputException& obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return username;
}


bool containsNonDigit(const std::string& phone) {
    for (char ch : phone) {
        if (!std::isdigit(ch)) {
            return true;
        }
    }
    return false;
}

std::string input_phone(std::istream& is) {
    std::string phone;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите номер телефона: ";
            std::getline(is, phone);

            // Проверка условий для номера телефона
            if (phone.length() != 11) {
                throw InputException(30, "Phone input error", "Номер телефона должен состоять из 11 цифр");
            }

            if (containsNonDigit(phone)) {
                throw InputException(31, "Phone input error", "Номер телефона должен содержать только цифры");
            }

        } catch (InputException& obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return phone;
}

std::string input_card(std::istream& is) {
    std::string card;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите номер банковской карты: ";
            std::getline(is, card);

            // Проверка условий для номера карты
            if (card.length() != 16) {
                throw InputException(40, "Card input error", "Номер карты должен состоять из 16 цифр");
            }

            if (containsNonDigit(card)) {
                throw InputException(41, "Card input error", "Номер карты должен содержать только цифры");
            }

        } catch (InputException& obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return card;
}

bool isValidDate(const std::string& str) {
    if (str.size() != 5 || str[2] != '/') {
        return false;
    }

    for (char ch : str) {
        if (!std::isdigit(ch) && ch != '/') {
            return false;
        }
    }

    std::istringstream ss(str);
    int month, year;
    char delimiter;
    ss >> month >> delimiter >> year;

    if (ss.fail() || delimiter != '/' || month < 1 || month > 12 || year < 0 || year > 99) {
        return false;
    }

    return true;
}

std::string input_date(std::istream& is) {
    std::string expirationDate;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите дату срока истечения карты (мм/гг): ";
            std::getline(is, expirationDate);

            // Проверка условий для даты
            if (!isValidDate(expirationDate)) {
                throw InputException(50, "Date input error", "Некорректная дата. Проверьте ввод");
            }

        } catch (InputException& obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return expirationDate;
}

bool containsNonLetter(const std::string& holderName) {
    for (char ch : holderName) {
        if (!std::isalpha(ch) && !std::isspace(ch)) {
            return true;
        }
    }
    return false;
}

std::string input_holdername(std::istream& is) {
    std::string holderName;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите имя владельца карты: ";
            std::getline(is, holderName);

            // Проверка условий для имени владельца карты
            if (holderName.empty()) {
                throw InputException(60, "Holder name input error", "Имя владельца карты не может быть пустым");
            }

            if (containsNonLetter(holderName)) {
                throw InputException(61, "Holder name input error", "Имя владельца карты должно содержать только буквы и пробелы");
            }

        } catch (InputException& obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return holderName;
}

bool isValidCVC(const std::string& cvc) {
    if (cvc.length() != 3) {
        return false;
    }

    for (char ch : cvc) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }

    return true;
}

int input_cvc(std::istream& is) {
    std::string cvcStr;
    int cvc = 0;
    bool flag;
    do {
        flag = true;
        try {
            std::cout << "Введите трехзначный код проверки карты (CVC): ";
            std::getline(is, cvcStr);

            // Проверка условий для CVC
            if (!isValidCVC(cvcStr)) {
                throw InputException(70, "CVC input error", "CVC должен состоять из трех цифр");
            }

            std::istringstream ss(cvcStr);
            ss >> cvc;

        } catch (InputException &obj) {
            std::cin.clear();
            obj.whatInput();
            flag = false;
        }

    } while (!flag);

    return cvc;
}