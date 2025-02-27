#include "PhoneBook.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook   phone;

    while (true)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        if (!std::getline(std::cin, cmd))
            break;
        if (!cmd.compare("ADD"))
            phone.add_contact();
        if (!cmd.compare("SEARCH"))
            phone.search();
        if (!cmd.compare("EXIT"))
            break;
    }
    return 0;
}