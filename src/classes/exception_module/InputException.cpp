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