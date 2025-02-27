#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm{

	private:
		const std::string _target;
        int _chance;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &p);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &p);

		const std::string get_target(void) const;

		void execute(const Bureaucrat &executor) const;

};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &p);

#endif