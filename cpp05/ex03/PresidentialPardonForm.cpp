#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("Nobody"){
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target){
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p), _target(p._target) {
    return;
}
PresidentialPardonForm::~PresidentialPardonForm(void){
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p){
    (void)p;
    return *this;
}

const std::string PresidentialPardonForm::get_target(void) const{
    return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	execute_check(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &p){
    o << "The target is " << p.get_name() << " for ";
   	o << "\"" << p.get_name() << "\" Presidential Pardon Form, require grade ";
	o << p.get_sign_grade() << " for signing it and grade ";
	o << p.get_exec_grade() << " for executing it. ";
	o << p.get_name();
	if (p.is_signed())
		o << " is signed.";
	else
		o << " isn't signed.";
	return o;
}