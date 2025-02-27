#include "Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain default constructor called" << std::endl;
    return;
}

Brain::~Brain(void){
    std::cout << "Brain destructor called" << std::endl;
    return;
}

Brain::Brain(const Brain &b){
    std::cout << "Brain copy constructor called" << std::endl;
    *this = b;
}

Brain &Brain::operator=(const Brain &b){
    std::cout << "Brain assignement constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = b.ideas[i];
    return *this;
}

void Brain::set_idea(const std::string idea){
    for (int i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

void Brain::thinking(void) const{
    // à toi qui va me corriger j'ai set la limite à 5 pour que ça ne flood pas d'idée à la con dans le terminal, libre à toi de la remettre à 100 ^^
    for (int i = 0; i < 5; i++)
        std::cout << this->ideas[i] << std::endl;
}