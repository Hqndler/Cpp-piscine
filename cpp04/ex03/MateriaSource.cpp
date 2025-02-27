#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
    for (int i = 0; i < 4; i++)
        items[i] = NULL;
    return;
}

MateriaSource::~MateriaSource(void){
    for (int i = 0; i < 4; i++)
        delete items[i];
    return;
}

MateriaSource::MateriaSource(const MateriaSource &ms){
    (void)ms;
    for (int i = 0; i < 4; i++)
        items[i] = ms.items[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms){
    (void)ms;
    for (int i = 0; i < 4; i++)
        items[i] = ms.items[i]->clone();
    return *this;
}

void MateriaSource::learnMateria(AMateria *m){
    int i = 0;
    while (i < 4 && items[i])
        ++i;
    if (i == 4){
        std::cout << "Full of materias, can't learn anymore" << std::endl;
        delete m;
        return;
    }
    items[i] = m;
    std::cout << "Learning " << m->get_type() << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
        if (items[i] && items[i]->get_type() == type)
            return items[i]->clone();
    std::cout << "Sorry, materia requested not learned yet : " << type << std::endl;
    return NULL;
}