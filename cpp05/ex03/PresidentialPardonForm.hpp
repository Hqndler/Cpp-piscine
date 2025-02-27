#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm{

	private:
		const std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &p);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &p);

		const std::string get_target(void) const;

		void execute(const Bureaucrat &executor) const;

};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &p);

#endif