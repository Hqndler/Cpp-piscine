#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat{

	private:
		const std::string _name;
		int _grade;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw(){
					return "Bureaucrat exception : Grade too high";
				}
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Bureaucrat exception : Grade too low";
				}
		};

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);

		const std::string &get_name(void) const;
		int get_grade(void) const;
		void upgrade(void);
		void downgrade(void);
		
		void sign_form(Form &f) const;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif