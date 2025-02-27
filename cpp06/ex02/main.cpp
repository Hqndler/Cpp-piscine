#include "Base.hpp"

int	main(){
	std::srand(std::time(0));
	for (int i = 0; i < 12; i++){
		Base * p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl;
		delete (p);
	}
    return 0; 
}