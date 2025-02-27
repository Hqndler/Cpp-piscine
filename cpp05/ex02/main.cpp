#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	AForm	*flex = 0;

	try
	{
		Bureaucrat	besos = Bureaucrat("Jeff", 5);

		// AForm	a = AForm();
		// std::cout << a << "\n\n";

		flex = new ShrubberyCreationForm("Norminet's garden");

		std::cout << *flex << "\n\n";
		besos.execute_form(*flex);
		besos.sign_form(*flex);
		std::cout << *flex << "\n\n";
		besos.execute_form(*flex);

		std::cout << "\n\n";

		delete flex;
		flex = new RobotomyRequestForm("Marvin");
		besos.sign_form(*flex);
		std::cout << *flex << "\n\n";

		for (int i = 0; i < 13; i++)
			besos.execute_form(*flex);

		std::cout << "\n\n";

		delete flex;
		flex = new PresidentialPardonForm("Marvin");
		besos.sign_form(*flex);
		std::cout << *flex << "\n\n";
		besos.execute_form(*flex);
	
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete flex;
	return (0);
}