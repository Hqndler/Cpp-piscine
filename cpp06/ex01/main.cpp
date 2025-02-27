#include "Serializer.hpp"

int	main()
{
	Data	magic_numbers = {42, 24};
	Data *	magic_ptr = &magic_numbers;
    // Serializer serialize = Serializer();

	std::cout << "pointer " << magic_ptr << " points to " << magic_ptr->key << " and " << magic_ptr->val << std::endl;

	uintptr_t	serial = Serializer::serialize(magic_ptr);
	std::cout << "serial is " << serial << std::endl;

	magic_ptr = Serializer::deserialize(serial);
	std::cout << "pointer " << magic_ptr << " points to " << magic_ptr->key << " and " << magic_ptr->val << std::endl;
}