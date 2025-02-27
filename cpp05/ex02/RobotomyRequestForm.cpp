#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("Nobody"), _chance(0){
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target), _chance(0){
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : AForm(p), _target(p._target), _chance(0){
    return;
}
RobotomyRequestForm::~RobotomyRequestForm(void){
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &p){
    (void)p;
    return *this;
}

const std::string RobotomyRequestForm::get_target(void) const{
    return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
    execute_check(executor);
    int random = rand();
    if (random % 2){
        std::cout << "** Brrrrr **" << std::endl;
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
        std::cout << "The robotomy for " << this->_target << " failed." << std::endl;
    return;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &p){
    o << "The target is " << p.get_name() << " for ";
   	o << "\"" << p.get_name() << "\" Robotomy Request Form, require grade ";
	o << p.get_sign_grade() << " for signing it and grade ";
	o << p.get_exec_grade() << " for executing it. ";
	o << p.get_name();
	if (p.is_signed())
		o << " is signed.";
	else
		o << " isn't signed.";
	return o;
}