#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("Unnamed"), _grade(150){
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw (GradeTooHighException());
	else
		this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b._name){
	if (b._grade > 150)
		throw(GradeTooLowException());
	if (b._grade < 1)
		throw(GradeTooHighException());
	else
		this->_grade = b._grade;
	return;
}

Bureaucrat::~Bureaucrat(void){
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b){
	this->_grade = b._grade;
	return *this;
}

const std::string &Bureaucrat::get_name(void) const{
	return this->_name;
}

int Bureaucrat::get_grade(void) const{
	return this->_grade;
}

void Bureaucrat::upgrade(void){
	if (this->_grade > 1)
		this->_grade--;
	else
		throw(GradeTooLowException());
}

void Bureaucrat::downgrade(void){
	if (this->_grade < 150)
		this->_grade++;
	else
		throw(GradeTooHighException());
}

void Bureaucrat::sign_form(Form &f) const{
	try{
		f.be_signed(*this);
		std::cout << this->_name << " signed " << f.get_name() << std::endl;
	}
	catch (std::exception &e){
		std::cout << this->_name << " couldn't sign " << f.get_name() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b){
	return o << b.get_name() << ", bureaucrat grade " << b.get_grade();
}