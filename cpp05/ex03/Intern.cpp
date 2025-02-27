#include "Intern.hpp"

Intern::Intern(void){
    return;
}

Intern::~Intern(void){
    return;
}

Intern::Intern(const Intern &i){
    (void)i;
    return;
}

Intern &Intern::operator=(const Intern &i){
    (void)i;
    return *this;
}

AForm *Intern::make_sc(const std::string &target) const{
    AForm *form = new ShrubberyCreationForm(target);
    return form;
}

AForm *Intern::make_pp(const std::string &target) const{
    AForm *form = new PresidentialPardonForm(target);
    return form;
}

AForm *Intern::make_rr(const std::string &target) const{
    AForm *form = new RobotomyRequestForm(target);
    return form;
}

AForm *Intern::make_form(const std::string &name, const std::string &target) const{
    std::string names[3] =  {"shrubbery creation", "presidential pardon", "robotomy request"};

    AForm *(Intern::*forms[3]) (const std::string &) const = {&Intern::make_sc, &Intern::make_pp, &Intern::make_rr};

    AForm *form;
    for (int i = 0; i < 3; i++){
        if (name == names[i]){
            form = (this->*forms[i])(target);
            std::cout << "Intern creates " << name << std::endl;
            return form;
        }
    }
    std::cerr << "`" << name << "` form doesn't exist." << std::endl;
    return NULL;
}