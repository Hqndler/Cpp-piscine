#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main()
{
	AForm	*flex = 0;

	try
	{
		Bureaucrat	besos = Bureaucrat("Jeff", 5);
		Intern	nobody = Intern();

		//Form	a = Form();
		//std::cout << a << "\n\n";

		flex = nobody.make_form("shrubbery creation", "Norminet's garden");

		std::cout << *flex << "\n\n";
		besos.execute_form(*flex);
		besos.sign_form(*flex);
		std::cout << *flex << "\n\n";
		besos.execute_form(*flex);

		std::cout << "\n\n";

		delete flex;
		flex = nobody.make_form("robotomy request", "Marvin");
		besos.sign_form(*flex);
		std::cout << *flex << "\n\n";

		for (int i = 0; i < 13; i++)
			besos.execute_form(*flex);

		std::cout << "\n\n";

		delete flex;
		flex = nobody.make_form("presidential pardon", "Marvin");
		besos.sign_form(*flex);
		std::cout << *flex << "\n\n";
		besos.execute_form(*flex);
	
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete flex;
}