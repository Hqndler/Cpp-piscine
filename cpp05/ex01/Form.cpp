#include "Form.hpp"

Form::Form(void) : _name("042"), _signed(false), _required_sign(150), _required_exec(150){
	return;
}

Form::~Form(void){
	return;
}

Form::Form(std::string name, const int sign, const int exec) : _name(name), _signed(false), _required_sign(sign), _required_exec(exec){
	if (sign < 1 || exec < 1)
		throw(GradeTooLowException());
	else if (sign > 150 || exec > 150)
		throw(GradeTooHighException());
	return;
}

Form::Form(const Form &f) : _name(f._name), _signed(f._signed), _required_sign(f._required_sign), _required_exec(f._required_exec) {
	return;
}

Form &Form::operator=(const Form &f){
	this->_signed = f._signed;
	return *this;
}

const std::string &Form::get_name(void) const{
	return this->_name;
}

int Form::get_sign_grade(void) const{
	return this->_required_sign;
}

int Form::get_exec_grade(void) const{
	return this->_required_exec;
}

bool Form::is_signed(void) const{
	return this->_signed;
}

void Form::be_signed(const Bureaucrat &b){
	if (b.get_grade() > this->_required_sign)
		throw(GradeTooLowException());
	else{
		if (this->_signed)
			throw(AlreadySigned());
		else
			this->_signed = true;
	}
}

std::ostream &operator<<(std::ostream &o, const Form &f){
	o << "\"" << f.get_name() << "\" form, require grade ";
	o << f.get_sign_grade() << " for signing it and grade ";
	o << f.get_exec_grade() << " for executing it. ";
	o << f.get_name();
	if (f.is_signed())
		o << " is signed.";
	else
		o << " isn't signed.";
	return o;
}
