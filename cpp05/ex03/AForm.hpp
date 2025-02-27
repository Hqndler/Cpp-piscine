#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{

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

		class NotSigned: public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Form exception : Form not signed";
				}
		};

	public:
		AForm(void);
		virtual ~AForm(void);
		AForm(const AForm &f);
		AForm(std::string name, const int sign, const int exec);
		AForm &operator=(const AForm &f);

		const std::string &get_name(void) const;
		int get_sign_grade(void) const;
		int get_exec_grade(void) const;
		bool is_signed(void) const;

		void be_signed(const Bureaucrat &b);

		virtual void execute(const Bureaucrat &executor) const = 0;
		void execute_check(const Bureaucrat &executor) const;

};

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif