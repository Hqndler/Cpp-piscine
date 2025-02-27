#include "AForm.hpp"

AForm::AForm(void) : _name("042"), _signed(false), _required_sign(150), _required_exec(150){
	return;
}

AForm::~AForm(void){
	return;
}

AForm::AForm(std::string name, const int sign, const int exec) : _name(name), _signed(false), _required_sign(sign), _required_exec(exec){
	if (sign < 1 || exec < 1)
		throw(GradeTooLowException());
	else if (sign > 150 || exec > 150)
		throw(GradeTooHighException());
	return;
}

AForm::AForm(const AForm &f) : _name(f._name), _signed(f._signed), _required_sign(f._required_sign), _required_exec(f._required_exec) {
	return;
}

AForm &AForm::operator=(const AForm &f){
	this->_signed = f._signed;
	return *this;
}

const std::string &AForm::get_name(void) const{
	return this->_name;
}

int AForm::get_sign_grade(void) const{
	return this->_required_sign;
}

int AForm::get_exec_grade(void) const{
	return this->_required_exec;
}

bool AForm::is_signed(void) const{
	return this->_signed;
}

void AForm::be_signed(const Bureaucrat &b){
	if (b.get_grade() > this->_required_sign)
		throw(GradeTooLowException());
	else
		this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const{
	std::cout << executor.get_name() << "is executing the " << this->_name << " form." << std::endl;
	return;
}

void AForm::execute_check(const Bureaucrat &executor) const{
	if (!this->_signed)
		throw(NotSigned());
	if (executor.get_grade() > this->_required_exec)
		throw(GradeTooLowException());
}

std::ostream &operator<<(std::ostream &o, const AForm &f){
	o << "\"" << f.get_name() << "\" AForm, require grade ";
	o << f.get_sign_grade() << " for signing it and grade ";
	o << f.get_exec_grade() << " for executing it. ";
	o << f.get_name();
	if (f.is_signed())
		o << " is signed.";
	else
		o << " isn't signed.";
	return o;
}
