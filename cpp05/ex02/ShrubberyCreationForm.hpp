#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{

	private:
		const std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &p);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &p);

		const std::string get_target(void) const;

		void execute(const Bureaucrat &executor) const;

};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &p);

#endif