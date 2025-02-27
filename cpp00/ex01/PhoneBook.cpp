#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
    return ;
}
PhoneBook::~PhoneBook(void){
    return ;
}

void PhoneBook::add_contact(void){
    Contact     contact;
    std::string input;
    std::string tab[5] = {"Name ?", "Last Name ?", "Nickname ?", "Phone Number ?", "Darkest secret ?"};
    int         count = -1;

    while (count < 5){
        if (count == 0)
            contact.set_name(input);
        if (count == 1)
            contact.set_last_name(input);
        if (count == 2)
            contact.set_nickname(input);
        if (count == 3)
            contact.set_number(input);
        if (count == 4){
            contact.set_secret(input);
            break ;
        }
        input = "";
        while (input.empty()){
            std::cout << tab[count + 1] << std::endl;
            if (!std::getline(std::cin, input))
                return ;
            if (input.empty())
                std::cout << "Input cannot be empty" << std::endl;
        }
        ++count;
    }
    this->_contact[this->_index % 8] = contact;
    this->_index++;
}

static std::string formated_string(std::string str){
    if (str.length() > 10){
        str = str.substr(0,9);
        str += ".";
    }
    return str;
}

static void pipe_setw(void){
    std::cout << "|";
    std::cout << std::setw(10);
}

void PhoneBook::show_all(void) const{
    int         limiter = this->_index;
    std::string str;

    std::cout << "/*******************************************\\" << std::endl;
    std::cout << "|     Index|      Name| Last Name|  Nickname|" << std::endl;
    if (limiter > 8)
        limiter = 8;
    for (int i = 0; i < limiter; i++){
        pipe_setw();
        std::cout << i + 1;
        pipe_setw();
        std::cout << formated_string(this->_contact[i].get_name());
        pipe_setw();
        std::cout << formated_string(this->_contact[i].get_last_name());
        pipe_setw();
        std::cout << formated_string(this->_contact[i].get_nickname());
        std::cout << "|";
        std::cout << str << std::endl;
    }
    std::cout << "\\*******************************************/" << std::endl;
}

void PhoneBook::show_contact(Contact contact) const{
    std::cout << "Name : " << contact.get_name() << std::endl;
    std::cout << "Last Name : " << contact.get_last_name() << std::endl;
    std::cout << "Nickname : " << contact.get_nickname() << std::endl;
    std::cout << "Phone Number : " << contact.get_number() << std::endl;
    std::cout << "Darkest secret : " << contact.get_secret() << std::endl;
    return ;
}

void PhoneBook::search(void) const{
    std::string input;

    show_all();
    std::cout << "Entrez l'index" << std::endl;
    if (!std::getline(std::cin, input))
        return ;
    if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
    {
        int nbr = input[0] - 48 - 1;
        if (nbr >= this->_index){
            std::cerr << "Le contact spécifié n'a pas été trouvé" << std::endl;
            return ;
        }
        return (show_contact(this->_contact[nbr]));
    }
    std::cerr << "Le contact spécifié n'a pas été trouvé" << std::endl;
    return ;
}

int PhoneBook::_index = 0;