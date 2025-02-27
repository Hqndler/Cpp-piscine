#include "Contact.hpp"

Contact::Contact(void){
    return ;
}
Contact::~Contact(void){
    return ;
}

std::string Contact::get_name(void) const{
    return this->_name;
}

std::string Contact::get_last_name(void) const{
    return this->_last_name;
}

std::string Contact::get_nickname(void) const{
    return this->_nickname;
}

std::string Contact::get_number(void) const{
    return this->_number;
}

std::string Contact::get_secret(void) const{
    return this->_secret;
}

void Contact::set_name(std::string str){
    this->_name = str;
}

void Contact::set_last_name(std::string str){
    this->_last_name = str;
}

void Contact::set_nickname(std::string str){
    this->_nickname = str;
}

void Contact::set_number(std::string str){
    this->_number = str;
}

void Contact::set_secret(std::string str){
    this->_secret = str;
}
