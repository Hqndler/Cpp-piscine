#include "Form.hpp"

int	main()
{
	try
	{
		std::cout << "Jeff the bureaucrat:\n";
		Bureaucrat	jeff = Bureaucrat("Jeff", 6);

		std::cout << jeff << std::endl;

		std::cout << "\nDefault form:\n";
		Form	a = Form();
		std::cout << a << "\n\n";

		std::cout << "Form b\n";
		Form	b = Form("B42", 6, 42);
		std::cout << b << "\n\n";

		std::cout << "Form c\n";
		Form	c = Form("C42", 6, 42);
		std::cout << b << "\n\n";

		std::cout << "Jeff sign form b\n";
		jeff.sign_form(b);
		std::cout << b << "\n\n";
		
		std::cout << "Jeff is downgraded\n";
		jeff.downgrade();

		std::cout << "Jeff trying to sign form c\n";
		jeff.sign_form(c);
		std::cout << c << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}