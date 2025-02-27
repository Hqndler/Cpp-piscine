#include "easyfind.hpp"

// void print_vect(std::vector<int> vect){
// 	std::cout << "[";
// 	for (size_t i = 0; i < vect.size(); ++i){
// 		std::cout << vect[i];
// 		if (i != vect.size() - 1)
// 			std::cout << ", ";
// 	}
// 	std::cout << "]" << std::endl;
// }

int main(void){
	//vector
	std::cout << "searching for 21 in a 42 vector container" << std::endl;
	std::vector<int> vect;
	vect.assign(42,42);
	vect[21] = 21;

	std::vector<int>::iterator itv = easyfind(vect, 21);
	if (itv != vect.end())
		std::cout << "found value " << *itv << std::endl;
	else
		std::cerr << "value not found" << std::endl;

	//deque
	std::cout << "searching for 21 in a 42 deque container" << std::endl;
	std::deque<int> deq;
	deq.assign(42,42);
	deq[21] = 21;

	std::deque<int>::iterator itq = easyfind(deq, 21);
	if (itq != deq.end())
		std::cout << "found value " << *itq << std::endl;
	else
		std::cerr << "value not found" << std::endl;

	//list    
	std::cout << "searching for 21 in a 42 list container" << std::endl;
	std::list<int> list;
	list.assign(42,42);
	list.front() = 21;

	std::list<int>::iterator itl = easyfind(list, 21);
	if (itl != list.end())
		std::cout << "found value " << *itl << std::endl;
	else
		std::cerr << "value not found" << std::endl;
	
	return 0;
}