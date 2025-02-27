#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{

	private:
		const std::string _name;
		bool _signed;
		const int _required_sign;
		const int _required_exec;

		class GradeTooHighException: public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Form exception : Grade too high";
				}
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Form exception : Grade too low";
				}
		};

		class AlreadySigned: public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Form exception : Form already signed";
				}
		};

	public:
		Form(void);
		~Form(void);
		Form(const Form &f);
		Form(std::string name, const int sign, const int exec);
		Form &operator=(const Form &f);

		const std::string &get_name(void) const;
		int get_sign_grade(void) const;
		int get_exec_grade(void) const;
		bool is_signed(void) const;

		void be_signed(const Bureaucrat &b);

};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif